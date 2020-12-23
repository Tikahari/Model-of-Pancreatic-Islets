import pickle as p
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import patches as mpatches
import sys

dat = p.load(open('distributions/'+sys.argv[1], 'rb'))
[x,y,z,s,m,r,b,b_prob] = dat
fig = plt.figure()
a = mpatches.Patch(color='red', label='Alpha')
b = mpatches.Patch(color='blue', label='Beta')
d = mpatches.Patch(color='green', label='Delta')
ax = fig.add_subplot(111, projection='3d')
ax.legend(handles=[a,b,d])
ax.set_title('Spatial Representation of Islet')
# ax.axis('off')
ax.scatter(x['A'], y['A'], z['A'], c='red', s=s['A'])
ax.scatter(x['B'], y['B'], z['B'], c='blue', s=s['B'])
ax.scatter(x['D'], y['D'], z['D'], c='green', s=s['D'])
plt.show()

# probability of alpha/beta/delta cells
fig,ax = plt.subplots(3)
x=np.linspace(0,r,100)
y = {'A': [], 'B': [], 'D': []}
for i in x:
	if i < r/3:
		if m*i +b >= b_prob:
			y['B'] = m*i+b
		else:
			y['B'] = b_prob
		y['A'] = (1-y['B'])/(1+r)
		y['D'] = 1-y['B']-y['A']
	else:
		y['B'] = b_prob
		y['A'] = (1-y['B'])/(1+r)
		y['D'] = 1-y['B']-y['A']
ax[0].plot(x,y['B'])
ax[0].set_title("Probability of Beta Cell vs Distance from Center")
ax[1].plot(x,y['A'])
ax[1].set_title("Probability of	Alpha Cell vs Distance from Center")
ax[2].plot(x,y['D'])
ax[2].set_title("Probability of	Delta Cell vs Distance from Center")
plt.subplots_adjust(hspace = 0.5)
plt.show()
