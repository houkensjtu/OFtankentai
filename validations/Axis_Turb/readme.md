## Turbulent flow in a 2D axis-symmetric channel

### Theory : What is Turbulence?

> The originial tutorial from [Wolfdynamics](http://www.wolfdynamics.com/images/pdf/turbulence_2019.pdf).

- Definition of turbulence is a very challenging issue due to its extremely complex nature and incomplete understanding of its theory. 
- Turbulence. Does it matter?
    - Usually the existence of turbulence enhances heat transfer, and lower the flow resistance (because the existence of many small vortexes in the flow region).   
![alt text](../../images/Axis_Turb/turb_intro1.png "turbintro")
![alt text](../../images/Axis_Turb/turb_intro2.png "turbintro")

### Modeling turbulence

#### Overivew
- The goal of turbulence modeling is to develop equations that predict **the time averaged** velocity, pressure, temperature fields without calculating the complete turbulent flow pattern as a function of time.
- There is **no universal turbulence model,** hence you need to know the capabilities and limitations of the turbulence models.
- Before doing a simulation or experiment, check if the flow is turbulent : 
![alt text](../../images/Axis_Turb/Re_def.png "Reynolds number")

- The boundary of Reynolds number between laminar and turbulence is roughly several thousands.
![alt text](../../images/Axis_Turb/Turb_Re.png "Turbulence transition")
![alt text](../../images/Axis_Turb/Re_region.png "Turbulence transition")

#### Turbulence models
- It's impractical to simulate all the fluctuation in the flow, thus we need modeling. To remove the instantaneous fluctuations or small scales, two methods can be used: Reynolds averaging and Filtering.

- Grid requirement : DNS > LES > RAS(RANS)

![alt text](../../images/Axis_Turb/Turbmodel.png "Turbulence models")

- As shown in the following graph, RANS is modeling all the eddies, while LES models to a certain level.

![alt text](../../images/Axis_Turb/energySpec.png "Turbulence energy")

#### Space/Time resolution requirment

#### Wall functions
- Wall functions will be applied to model flow near the wall. Usually y+ < 30 can be modeled.
- Wall functions can be used in RANS, LES, DES, but obviously not DNS.

![alt text](../../images/Axis_Turb/wallfunc.png "Wall functions")

-Generally speaking, wall functions is the approach to use if you are more interested in 
the mixing in the outer region, rather than the forces on the wall. **If accurate prediction of forces or heat transfer on the walls are key to your simulation (aerodynamic drag, turbomachinery blade performance, heat transfer) you might not want to use wall functions.**

