from matplotlib.pyplot import *
from numpy import *

system = False
earth_sun = False
earth_sun_jupiter = True

euler = False
verlet = True

pluto = False

if system == True:
    print 'Plotting the solar system.'
if earth_sun == True:
    print 'Plotting the Earth-Sun system.'
if earth_sun_jupiter == True:
    print 'Plotting the Earth-Sun-Jupiter system.'

if pluto == True:
    print 'Pluto is included.'

if euler == True:
    print 'Using forward Euler.'
if verlet == True:
    print 'Using velocity Verlet.'

if system == True:
    if verlet == True:
        A = genfromtxt("positions_system_verlet_250years_dt0_0001_TRUE.xyz")
#    if euler == True:
#        A = genfromtxt('positions_system_euler.xyz')

    if pluto == True:
        sx, sy, mx, my, vx, vy, ex, ey, mrx,mry, jx, jy, sax,say, ux,uy, nx,ny, px,py = A[:,0], A[:,1], A[:,3], A[:,4], A[:,6], A[:,7], A[:,9], A[:,10], A[:,12], A[:,13], A[:,15],A[:,16], A[:,18], A[:,19], A[:,21], A[:,22], A[:,24], A[:,25], A[:,27], A[:,28]
    else:
        sx, sy, mx, my, vx, vy, ex, ey, mrx,mry, jx, jy, sax,say, ux,uy, nx,ny = A[:,0], A[:,1], A[:,3], A[:,4], A[:,6], A[:,7], A[:,9], A[:,10], A[:,12], A[:,13], A[:,15],A[:,16], A[:,18], A[:,19], A[:,21], A[:,22], A[:,24], A[:,25]

    plot(sx, sy, 'ro', label = "Sun")
    plot( mx, my, label = "Mercury")
    plot( vx, vy, 'k-', label = "Venus")
    plot(ex,ey,'g-',label = 'Earth')

    plot( mrx, mry, 'r-', label = "Mars")
    plot( jx, jy, label = "Jupiter")
    plot( sax, say, label = "Saturn")
    plot( ux, uy, 'b-', label = "Uranus")
    plot( nx, ny, label = "Neptune")
    if pluto == True:
        plot( px, py, label = "not-a-planet")

    legend(loc = 'best')
    grid('on')
    axis('equal')
    xlabel('x-distance [AU]')
    ylabel('y-distance [AU]')
    #show()
    if verlet == True:
        savefig('solar_system_250yr_verlet_dt0_0001_TRUE.png')
#    if euler == True:
#        savefig('solar_system_200yr_euler.png')

if earth_sun == True:
    if verlet == True:
        A = genfromtxt('positions_earth_sun_verlet_5years_dt0_001.xyz')
    if euler == True:
        A = genfromtxt('positions_earth_sun_euler_5years_dt0_001.xyz')

    sx, sy, ex, ey = A[:,0], A[:,1], A[:,3], A[:,4]

    plot(sx, sy, 'ro', label = "Sun")
    plot(ex,ey,'g-',label = 'Earth')
    
    legend(loc = 'best')
    grid('on')
    axis([-1.5, 1.5, -1.5, 1.5])
    xlabel('x-distance [AU]')
    ylabel('y-distance [AU]')
    #show()

    if verlet == True:
        savefig('earth_sun_verlet_5years_dt0_001.png')
    if euler == True:
        savefig('earth_sun_euler_5years_dt0_001.png')

if earth_sun_jupiter == True:
    if verlet == True:
        A = genfromtxt('positions_esj_verlet_25years_dt0_00001_MJ1000.xyz')

    sx, sy, ex, ey, jx, jy = A[:,0], A[:,1], A[:,3], A[:,4], A[:,6], A[:,7]
    plot(sx, sy, 'ro', label = "Sun")
    plot(ex,ey,'g-',label = 'Earth')
    plot( jx, jy, label = "Jupiter")

    legend(loc = 'best')
    grid('on')
    axis('equal')
    xlabel('x-distance [AU]')
    ylabel('y-distance [AU]')

    if verlet == True:
        savefig('earth_sun_jupiter_verlet_25yr_dt0_00001_MJ1000.png')


