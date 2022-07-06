<br/>
<p align="center">
  <a href="https://github.com/Grigory Pichugin/TestGeometry">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/29/Helix.svg/220px-Helix.svg.png" alt="Logo" width="200" height="200">
  </a>

  <h1 align="center">Curves</h1>

  <p align="center">
    Test task for CAD Exchanger <img src="https://3dtoday.ru/upload/posts/main/1tkguNb6Q68YEUDsUJjdkqIJEeaCiOPHUjRelG3V54QoKEpJwr.jpg">
    <br/>
    <br/>
    <a href="https://github.com/gpicugin/TestGeometry"><strong>Explore the docs »</strong></a>
    <br/>
    <br/>    
  </p>
</p>



## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Usage](#usage)
* [Author](#author)

## About The Project

Dll defines classes of curves, such as Circle, Ellipse and Helix and gives API to work with it.
Project main includes main.cpp, which code do next:
- creates two containers(to store Curves of all types and to store only Circles);
- fills 1st container with random generated Curves;
- saves to file Data.txt coordinates of points and derivatives of all curves in the 1st container at t=PI/4;
- copies all Circle pointers from 1st to 2nd container;
- sorts pointers via radii forn min to max;
- calculates sum of radii from 2nd container;
- print to console number of Circles and sum of their radii;

## Built With

This programm was written on MS Visual Studio 2019 using Windows SDK 10.0 and Platform Toolset v142 without pre-compiled headers.
The solution is on TestGeomery Folder.
Geometry folder contains source code of dll.
Main folder contains code using it to do a task from your letter.

## Usage

This source code may to use for build curves and tangents lines in definite point

## Author

* **Grigory Pichugin** - *C++ Programmer* - [Grigory Pichugin](https://github.com/gpicugin)

