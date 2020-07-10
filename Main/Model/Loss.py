from matplotlib import pyplot as plt

threshold = 60

class Loss:
    def __init__(self, mean, slope):
        self.mean = mean
        self.slope = slope
    def getLoss(self, val):
        if abs(self.mean-val) < threshold:
            return 0
        return self.slope*abs((self.mean - val)-threshold))
    def plot(self):
        x = []
        i = self.mean - threshold*3
        while i < self.mean + threshold*3:
            x.append(self.getLoss(i))
            i += 1
        plt.plot(x)
        plt.show()
l = Loss(55, 2)
l.plot()