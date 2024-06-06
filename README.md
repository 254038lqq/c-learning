## Application Project Introduction
### Project Structure
A cleaned original application project is like below.

Note: This application project is cannot directly run, as the named `svapp` binary file is not generated under the root directory.
```
appName
├── README.md
├── config
│   ├── camera.config
│   ├── defect.config
│   └── model.config
├── lib
├── manager.sh
├── model
├── release.txt
└── src
    ├── CMakeLists.txt
    ├── example.cpp
    ├── example.hpp
    ├── example_v0.2.cpp
    └── model.cpp
```
#### Project Introduction
* **manager.sh**

  a key script file exposed to external system to control application life cycle management. If you do not fully understand the implementation of the script, it is best not to modify it to avoid affecting further normal use.

* **release.txt**

  it is generated automatically by the `appc` tool, include the application id, name, version, description and the relevant model information.

  * **config**

    the directory contains the following configuration files that the algorithm application depends on when it is actually run.
    * model.config

      Created by parsing the model zip package come from AIC system, if configured the `--model` or `-m` option. But it is not specified when to create application project, manual modification for this file is needed.
  
    * camera.config

      the default setting for the physical camera is provided below:
    
      ```
      {
        "triggerWay": 1,            # 0: IO trigger; 1: continus trigger
        "rimType": 1,               # 0: up rim;     1: down rim
        "triggerDelay": 0,
        "triggerFrequency": 30,
        "autoExposure": true,
        "exposureTime": 0,
        "sensitivity": 0,
        "format" : 35,
        "autoFocus": true,
        "autoWhiteBalance": true,
        "colorCorrectionGains": [1.0, 1.0, 1.0, 1.0],
        "colorCorrectionTransform": [1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1],
        "height": 480,
        "width": 640
      }
      ```
    * defect.config

      Various defect rejection standards set by users based on different inspection targets, need to follow the json data format. Here is a example for this config:
      ```
      [{
        "key": "huashang",
        "type": 1, // 数值
        "name": "划伤",
        "data": {"area": 8, "length": 5, "energy": 9}
      }, {
        "key": "gubao",
        "type": 2, // 开关
        "name": "鼓包",
        "data": {"isOpen": true}
      }, {
        "key": "qujian",
        "type": 3, // 取值区间
        "name": "名称1",
        "data": {"minValue": 14,"maxValue": 25}
      }]
      ```
* **model**

  if configured the `--model` or `-m` option, all files in the zip package come from AIC system are extracted under this directory.
* **lib**

  Relevant library files that the application compiles and runs depend on are placed in this directory.
* **src**

  A demo application implemented in C++ source code. User can change it if according to actual implementation.

### Project Compile
  the following steps is how to compile the whole source files to named `svapp` binary.
  ```
  cd src
  mkdir build
  cd build
  cmake ..
  make
  ```

