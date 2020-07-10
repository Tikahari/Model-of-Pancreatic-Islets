from matplotlib import pyplot as plt


class Loss:
    def __init__(self, mean, slope, threshold, path):
        self.mean = mean
        self.slope = slope
        self.threshold = threshold
        self.path = path
    def getLoss(self, val):
        if abs(self.mean-val) < self.threshold:
            return 0
        elif self.mean - val > self.threshold:
            return self.slope*abs((self.mean - val)-self.threshold)
        elif self.mean - val < self.threshold:
            return self.slope*abs((self.mean - val)+self.threshold)
    def plot(self):
        x = []
        i = self.mean - self.threshold*3
        while i < self.mean + self.threshold*3:
            x.append(self.getLoss(i))
            i += 1
        plt.clf()
        plt.plot(x)
        plt.title('Loss function')
        plt.xlabel('Curve Transformation')
        plt.ylabel('Score')
        plt.savefig(self.path)
        # plt.show()
# l = Loss(55, 2, 'name')
# l.plot()