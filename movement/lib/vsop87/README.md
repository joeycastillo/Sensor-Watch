# Example

An example in JavaScript showing computations is available at http://www.celestialprogramming.com/vsop87-multilang/

### Current Stauts
Versions for many different languages and environments have been created.  These have passed all test cases provided by the
VSOP87 authors, a validation program is also included for each language.  They are ready for use. See the "Languages" directory for the status
of each language.

Still to come: more languages, documentation, and examples.

# About this Project
The purpose of this project is to create versions of VSOP87 in many different languages.  The plan is to generate a initial version in C# truncated to different
precisions, then convert the resulting files into other languages.  This project was inspired by the [Neoprogrammics Source Code Generator Tool](http://www.neoprogrammics.com/vsop87/source_code_generator_tool/).
The goal of this project is to provide easier to use (readymade source files), include all data (e.g. the Moon and velocities), are truncated to different accuracy levels,
, for more languages, and have a more permissive license (public domain).  It will provide tests against the original VSOP87 test data for each programming language to validate correctness, as well as examples to show common useage.

# Language Status

Below is a list of the planned languages and their current status.


Language     |Inline|JSON|CSV|CSV Low Mem|Validation Tests|Alt Az Reduction Example
-------------|------|----|---|-----------|----------------|--------------
Java         |Yes   |    |Yes|           |Pass            |
C            |Yes   |    |   |Yes        |Pass            |
C#           |Yes   |    |Yes|           |Pass            |
Python       |Yes   |Yes |Yes|           |Pass            |
C++          |Yes   |    |   |           |Pass            |
VB.Net       |Yes   |    |   |           |Pass            |
JavaScript   |Yes   |Yes |   |           |Pass            |Yes
PHP          |Yes   |    |   |           |Pass            |
Ruby         |Yes   |    |   |           |Pass            |
Swift        |Yes   |    |   |           |Pass            |
Matlab/Octave|Yes   |    |   |           |Pass            |
Groovy       |      |    |Yes|           |Pass            |
Go           |Yes   |    |   |           |Pass            |
Pascal       |Yes   |    |   |           |0.000009au      |
Perl         |Yes   |    |   |Yes        |Pass            |
R            |Fail! |    |   |           |Fail!           |
Cobol        |      |    |   |           |                |
Fortran      |      |    |   |           |                |
Rust         |Yes   |    |   |           |Pass            |
Arduino      |Yes   |    |   |           |0.000009au      |

# What is VSOP87? Why use it?
VSOP87 is one of many solutions available for predicting the positions of the planets (plus the Sun and the Moon) in our solar system.  The actual name is
Variations S�culaires des Orbites Plan�taires, and it was published in 1987 by the Bureau des Longitudes.  Even though there have been many other methods
developed before and after VSOP87, it remains one of the most popular methods among amatuers.  It provides better accuracy than most amatuers require (.1 arcseconds)
over a period of a few thousand years before and after the year 2000.

# Implementation Types
There are a few different types of implementations: Inline, JSON, CSV, and CSV Low Memory.  The inline versions are generally the easiest to use as they will have no
external requirements, they are also the easiest to generate, so they're available for more languages.  The JSON versions require a JSON file (located in the 
languages/JSON folder) which is loaded into memory.  The advantages of the JSON versions are you can compute the velocities with the same data the positions
are generated from, and you can load and dispose of the memory used by the data when you need it.  The CSV implementations are similar to the JSON implementations, 
but, obviously, read from a CSV file (located in the languages/CSV folder). And the Low Memory CSV implementations read the same CSV files, but the
data is not retained in memory.  The JSON versions are located in the Languages/JSON directory, as well as the required JSON files, and the CSV implementations
are in the languages/CSV folder.

# Which Version Should I Use?
For the overwhelming majority of users, the VSOP87A_full version will be all that you need.  This is the full version, but should still be fast enough and small enough
for most use cases.  Using the full version eliminates any questions of whether it will be accurate enough.  If, after trying the full version, the computation isn't
fast enough, from there you should experiment with truncated versions.  The VSOP87A versions are the only versions which include both the Earth and Moon.  VSOP87A doesn't include the moon directly, but does include the Earth and the Earth-Moon Barrycenter, and all provided code for the VSOP87A versions include a function to compute the Moon's position from the Earth and EMB.  Using the versions that provide the velocities is necessary if you want to account for relativistic effects do to the motion of the observer.

There are several versions of the main theory.  The first is just called VSOP87, the remainder of them are appended with the letters A, B, C, D, E.  Each version
provides the data in a slightly different form.

Version|Mercury|Venus|Earth|EMB|Mars|Jupiter|Saturn|Uranus|Neptune|Sun|Coordinates
-------|-------|-----|-----|---|----|-------|------|------|-------|---|-----------
VSOP87|Yes|Yes|No|Yes|Yes|Yes|Yes|Yes|Yes|No|Keperian Orbital Elements
VSOP87A|Yes|Yes|Yes|Yes|Yes|Yes|Yes|Yes|Yes|No|Heliocentric J2000 Ecliptic Rectangular XYZ
VSOP87B|Yes|Yes|Yes|No|Yes|Yes|Yes|Yes|Yes|No|Heliocentric J2000 Ecliptic Spherical LBR
VSOP87C|Yes|Yes|Yes|No|Yes|Yes|Yes|Yes|Yes|No|Heliocentric Ecliptic of date Rectangular XYZ
VSOP87D|Yes|Yes|Yes|No|Yes|Yes|Yes|Yes|Yes|No|Heliocentric Ecliptic of date Spherical LBR
VSOP87E|Yes|Yes|Yes|No|Yes|Yes|Yes|Yes|Yes|Yes|Barycentric J2000 Ecliptic Rectangular XYZ

# Truncated versions
Since the full VSOP87 provides more accuracy than most amateurs require, the algorithm can be shortened by eliminating terms.  This speeds up the computations, and
reduces the overall size of the code at the cost of accuracy.  For each programming language, this project supplies VSOP87 truncated at ten different levels.  The
effects of accuracy are detailed in the graphs below.  Each level of truncation eliminates any terms with a coefficient 1/10 the previous truncation level.

Trunaction Level|Total Terms|Skipped Terms|Percent Skipped
----------------|-----------|-------------|---------------
full 	 |269949|0     |0 %
xx large |269949|20998 |7.7 %
x large  |269949|67848 |25.1 %
large 	 |269949|145031|53.7 %
small 	 |269949|218559|80.9 %
x small  |269949|250204|92.6 %
milli 	 |269949|262369|97.1 %
micro 	 |269949|266975|98.8 %
nano 	 |269949|268686|99.5 %
pico 	 |269949|269464|99.8 %

# Accuracy

Accuracy graphs are below.  They show the error in degrees of each body as viewed from Earth.  Each graph shows the error for one body for all truncated versions of
VSOP87.  The error is vs. the full version of VSOP87, so the inherent error in VSOP87 also has to be added.  Some bodies appear twice, to zoom in on the lower portion
of the graph, as the error of the pico version makes it difficult to see errors amongst the larger versions.  The Python script and data to reproduce the graphs is
in the Accuracy folder, by regenerating them you can use the Matplotlib interface to explore the graphs further.

Since the error is computed from the geocenter, the Earth does not appear in the graphs below, nor does the Sun.  Graphs are also not present for the Moon, but graphs
are available for the Earth-Moon Barrycenter (EMB), the error for the Moon will be a linear function of the EMB error.

The full VSOP87 accuracy is .1 arcseconds for Saturn, and better for all others.  For more details on accuracy of the full theory consult
[Planetary theories in rectangular and spherical variables - VSOP 87 solutions](http://articles.adsabs.harvard.edu/full/1988A%26A...202..309B).

### Mercury
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/mercury.png)

### Venus
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/venus.png)

### Earth-Moon Barrycenter
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/emb.png)

### Earth-Moon Barrycenter (zoomed)
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/emb2.png)

### Mars
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/mars.png)

### Jupiter
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/jupiter.png)

### Saturn
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/saturn.png)

### Saturn (zoomed)
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/saturn2.png)

### Uranus
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/uranus.png)

### Uranus (zoomed)
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/uranus2.png)

### Neptune
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/neptune.png)

### Neptune (zoomed)
![Mercury](https://raw.githubusercontent.com/gmiller123456/vsop87-multilang/master/utility/Accuracy/neptune2.png)
