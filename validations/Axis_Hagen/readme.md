## Laminar flow in a 2D axis-symmetric channel

There are several solvers available for incompressible flow. See the table below :
![alt text](../../images/Axis_Hagen/solvers.png "Solvers")
icoFoam is argubaly the simplest solver to use since it require the least parameters, no turbulence required. Therefore, we use icoFoam in this first validation case.

### Mesh setup 

A 10 degree wedge shape model was made to represent the 2D axis-symmetric channel. The lenght of the channel is 1m and the diameter is 0.1m. (So the radius being 0.05m) In the blockMeshDict file, however, one have to give the calculated vertex position based on the 5 degree.
```
vertices
(
    (0 0 0)
    (10 0 0)
    (10 0.49809734 0.04357787)
    (0 0.49809734 0.04357787)
    (0 0.49809734 -0.04357787)
    (10 0.49809734 -0.04357787)
);

blocks
(
    hex (0 4 3 0 1 5 2 1) (20 1 400) simpleGrading (1 1 1)
);
```
![alt text](../../images/Axis_Hagen/mesh.png "blockmesh")


### Boundary condition

There are two sets of boundary conditions in OpenFoam, base type and primitive type. Base type, including patch, wall and others, is applied in ./constant/polymesh/boundary. Primitive type, including specific numerical condition, for example zeroGradient, is applied in ./0/U,p...

