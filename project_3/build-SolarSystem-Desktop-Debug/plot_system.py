from matplotlib.pyplot import *
from numpy import *
A= genfromtxt("positions_f.xyz")
sx, sy, mx, my, vx, vy, ex, ey, mrx,mry, jx, jy, sax,say, ux,uy, nx,ny, px,py = A[:,0], A[:,1], A[:,3], A[:,4], A[:,6], A[:,7], A[:,9], A[:,10], A[:,12], A[:,13], A[:,15],A[:,16], A[:,18], A[:,19], A[:,21], A[:,22], A[:,24], A[:,25], A[:,27], A[:,28]


plot(sx, sy, 'r-', label = "Sun")
plot( mx, my, label = "Mercury")
plot( vx, vy, 'k-', label = "Venus")
plot(ex,ey,'g-',label = 'Earth')
plot( mrx, mry, 'r-', label = "Mars")
plot( jx, jy, label = "Jupiter")
plot( sax, say, label = "Saturn")
plot( ux, uy, 'b-', label = "Uranus")
plot( nx, ny, label = "Neptune")
plot( px, py, label = "not-a-planet")
#legend(loc = 'best')
grid('on')
#axis('equal')
#axis([-1.5,1.5,-1.5,1.5])
xlabel('x-distance [AU]')
ylabel('y-distance [AU]')
show()
#savefig('solar_system')
