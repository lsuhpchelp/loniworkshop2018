#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt
nprocs=8
p=2**np.arange(0,nprocs).reshape(nprocs,-1)
n=2**np.arange(0,6)*10

T_serial  =n**2
T_parallel=n**2/p+np.log2(p)
# FIXME: calculate Speedup and Efficiency
# The solution should be very simple if you know numpy's array broadcasting
S=
E=

plt.subplot(2,2,1)
plt.plot(p,S,marker='s')
str_legend=['n='+str(_n) for _n in n]
plt.legend(str_legend,numpoints=1, loc='upper left') #, bbox_to_anchor=(1, 0.5))
plt.xlabel('p')
plt.ylabel('Speedup')
plt.title('Speedup: n=constant, increase p')

plt.subplot(2,2,2)
plt.plot(p,E,marker='o')
str_legend=['n='+str(_n) for _n in n]
plt.legend(str_legend,numpoints=1, loc='lower left') #, bbox_to_anchor=(1, 0.5))
plt.xlabel('p')
plt.ylabel('Efficiency')
plt.title('Efficiency: n=constant, increase p')

plt.subplot(2,2,3)
plt.plot(n,S.T,marker='s')
str_legend=['p='+str(_p[0]) for _p in p]
plt.legend(str_legend,numpoints=1, loc='center left', bbox_to_anchor=(1, 0.5))
plt.xlabel('n')
plt.ylabel('Speedup')
plt.title('Speedup: p=constant, increase n')
#plt.legend(

plt.subplot(2,2,4)
plt.plot(n,E.T,marker='o')
str_legend=['p='+str(_p[0]) for _p in p]
plt.legend(str_legend,numpoints=1, loc='lower right') #, bbox_to_anchor=(1, 0.5)))
plt.xlabel('n')
plt.ylabel('Efficiency')
plt.title('Efficiency: p=constant, increase n')
#plt.legend(

plt.tight_layout()
plt.show()
