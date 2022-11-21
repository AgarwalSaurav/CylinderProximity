# CylinderProximity
The repository contains Mathematica and C++ programs for our paper on "Analytical Determination of the Proximity of Two Right-Circular Cylinders in Space." Please use the citation below if you find the programs useful. The paper can be downloaded from my webpage: [saurav.fyi/publications](https://www.saurav.fyi/publications).

```
Agarwal, S., Srivatsan, R. A., and Bandyopadhyay, S.
"Analytical Determination of the Proximity of Two Right-Circular Cylinders in Space."
ASME Journal of Mechanisms and Robotics. August 2016; 8(4): 041010.
https://doi.org/10.1115/1.4032211
```

Bibtex:
```
@article{CylinderProximity_ASME16,
    author = {Agarwal, Saurav and Srivatsan, Rangaprasad Arun and Bandyopadhyay, Sandipan},
    title = {Analytical Determination of the Proximity of Two Right-Circular Cylinders in Space},
    journal = {Journal of Mechanisms and Robotics},
    volume = {8},
    number = {4},
    year = {2016},
    month = {03},
    issn = {1942-4302},
    doi = {10.1115/1.4032211},
}
```

## Description
There are two versions of the code: one in Mathematica and the other in C++. The Mathematica code comprises the closed-form solutions for the computation of proximity between two cylinders. The C++ code was developed for faster computation using the closed-form solutions from Mathematica.

This work was done during the very early years of my research journey, and I was a far worse programmer. The code is not documented; I hope to do that someday. Although the code was tested rigorously, new bugs wouldn't be surprising. Bugs can be reported using GitHub ``Issues``. ``Pull requests`` are great too!

## C++ Installation
Run `bash setup.bash` inside the `CPP` folder.  
`./bin/CylinderProximity` to execute the binary.  
See `CPP/src/main.cpp` for a sample `main` function.

## Possible Caveats
A very refreshing way of thinking about the problem was presented by Professor Zsombor-Murray in the paper below. A possible case that may have been missed in our formulation was also discussed. We gratefully acknowledge Professor Zsombor-Murray's valuable input on the problem.

```
Zsombor-Murray, P. (2018).
"Intrusion, Proximity and Stationary Distance."
In: Zeghloul, S., Romdhane, L., Laribi, M. (eds) Computational Kinematics.
Mechanisms and Machine Science, vol 50. Springer, Cham.
https://doi.org/10.1007/978-3-319-60867-9_54
```
## License and Acknowledgments
The work was conducted at the Indian Institute of Technology (IIT) Madras, India, with Dr. Arun Srivatsan and Dr. Sandipan Bandyopadhyay. My coauthors bear no responsibility for the inaccuracy of the programs.
Details about my research can be found on my website: [saurav.fyi](https://www.saurav.fyi)

The program uses GNU Scientific Library (GSL) for solving equations.  
The program is open source and is available to use under the GPL license.

Copyright 2015-2022, IIT Madras for Mathematica program

Copyright 2015-2022, Saurav Agarwal for C++ program


CylinderProximity is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
