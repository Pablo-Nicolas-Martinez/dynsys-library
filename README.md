# Dynamical systems in C++

## Objectives

Welcome to the dynsys-library. The objective of the code is to provide some basic classes, like vectors, grids and abstract differential equations. There is also an implementation of several routines related to each method: from basic algebraic operations to Lagrangian functions defined on a grid. A more detailed description of each class and the routines implemented can be found in the [wiki](https://github.com/Pablo-Nicolas-Martinez/dynsys-library/wiki) of the project.

The file testduffing.cpp is an example of application of the code. A 200 by 200 lattice is generated and the Lagrangian function over the whole lattice is computed by a fourth order Runge-Kutta method and numerical integration.

## Downloading and using the code

To access the code simply clone the repository on your machine and compile it. The headers and declarations can be found in the include/ folder, while executables are located in bin/. If you detect any anomaly on the code or you have a proposal, please create a pull request with specification of the changes and a brief explanation.

## License

This work has been developed under an MIT license. For more details have a look at the [LICENSE](https://github.com/Pablo-Nicolas-Martinez/dynsys-library/blob/master/LICENSE) document.

## Support and thanks

This library has been developed for the course ''Dynamical Systems and applications'', which was part of the 2020 Severo Ochoa grant programme for introduction to research, offered by the ICMAT. I would like to thank the help of Weijie Chen and Emilio Domínguez Sánchez, who have done several contributions to the code and pointed out possible reformulations. Moreover, I would like to thank my tutor, José Antonio Jiménez Madrid, and remark his dedication and help throughout the course.
