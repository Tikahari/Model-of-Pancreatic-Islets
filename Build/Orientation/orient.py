"""This script determines the position of an alpha/beta/delta cell"""
import numpy as np
from matplotlib import pyplot as plt
from scipy.stats import expon
import seaborn as sns

# space = np.zeros(1000,1000,1000)
# 60% chance of b-cell, 20% of a-cell, 10% of d-cell
cells = [0.6, 0.8, 1]
# b-cell probability distribution
beta = expon.rvs(scale=1,loc=0,size=1000)

ax = sns.distplot(beta,
                  kde=True,
                  bins=100,
                  color='skyblue',
                  hist_kws={"linewidth": 15,'alpha':1})
ax.set(xlabel='Exponential Distribution', ylabel='Frequency')