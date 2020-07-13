from scipy.signal import butter, lfilter, find_peaks, peak_prominences, freqz, kaiserord, firwin
import numpy as np
import matplotlib.pyplot as plt

# frequency is the number of times a wave repeats a second
frequency = [15, 30, 35]
num_samples = 300
 
# The sampling rate of the analog to digital convert
sampling_rate = 100

# create sine waves
sine_wave = []
t = [i for i in range(num_samples)]
c = 0
for i in frequency:
    sine_wave.append([np.sin(2 * np.pi * i * x/sampling_rate) for x in range(num_samples)])\

# combine sine waves
combined = []
for i in sine_wave:
    for j in range(len(i)):
        if len(combined) <= j:
            combined.append(0)
        combined[j] += i[j]
for i in sine_wave:
    plt.plot(t, i)
plt.title("Initial Waveforms")
plt.ylabel("Amplitude")
plt.xlabel("Time [s]")
plt.show()

plt.plot(combined)
plt.title("Combined Waveforms")
plt.ylabel("Amplitude")
plt.xlabel("Time [s]")
plt.show()

# fourier transform to visualize frequencies instead of amplitude
fft = np.fft.fft(combined)
plt.bar(t[:len(t)//2], np.abs(fft)[:len(fft)//2])
plt.title("Frequency Domain of Combined Waveforms")
plt.ylabel("Amplitude")
plt.xlabel("Frequency [Hz]")
plt.show()

# low pass filter

# Nyquist frequency
nyq = sampling_rate / 2

# width of transition band
width = 0.01

# The desired attenuation in the stop band, in dB.
ripple_db = 20.0

# Compute the order and Kaiser parameter for the FIR filter.
N, beta = kaiserord(ripple_db, width)

# The cutoff frequency of the filter.
cutoff_hz = 6.0

# Use firwin with a Kaiser window to create a lowpass FIR filter.
taps = firwin(N, cutoff_hz/nyq, window=('kaiser', beta))
# print('coefficients', taps)
w, h = freqz(taps, worN=100)
plt.plot((sampling_rate * 0.5 / np.pi) * w, abs(h), label="order = %d" % N)
plt.show()

# fig, axs = plt.subplots(2, 1)
# axs[0].plot(b)
# axs[1].plot(a)
# plt.show()

# low pass
y = lfilter(taps, 1.0, combined)
plt.plot(y)
plt.show()

# fourier transform filtered data to check results
fft = np.fft.fft(y)
plt.bar(t[:len(t)//2], np.abs(fft)[:len(fft)//2])
plt.title("Frequency Domain of Combined Waveforms")
plt.ylabel("Amplitude")
plt.xlabel("Frequency [Hz]")
plt.show()
