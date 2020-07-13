"""The 'Loss' object will provide a simple interface with the loss function that will be used to determine the score of each cell and islet"""
from matplotlib import pyplot as plt
import sys

class Loss:
    def __init__(self, mean, slope, threshold, path):
        """"Initialize loss function"""
        # set object variables
        self.mean = mean
        self.slope = slope
        self.threshold = threshold
        self.path = path
    def getLoss(self, val):
        """Get value of loss function for cell"""
        if abs(self.mean-val) < self.threshold:
            return 0
        elif self.mean - val > self.threshold:
            return self.slope*abs((self.mean - val)-self.threshold)
        return self.slope*abs((self.mean - val)+self.threshold)
    def plot(self):
        """Visualize loss function"""
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
if __name__ == '__main__':
    # test
    # python Loss.py -40 20 1
    loss =Loss(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
    loss.plot()