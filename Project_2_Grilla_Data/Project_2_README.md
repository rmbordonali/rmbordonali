### Project Description:
This project builds on Project 1 with a focus on passive seismics. This project was created using data downloaded from TROMINO GRILLA software.

### Code Summary:
- Linearly detrending data
- Normalizing data
- Shifting data to zero mean
- Subsampling data
- Tapering data with Hann window
- Fast Fourier transform (FFT) spectra
  - Combining horizontal (north-south and east-west) FFT magnitudes
- Power spectral density plots with Welch's method
- Horizontal-to-vertical spectral ratio (HVSR)
- Short time Fourier transform (STFT) spectrograms with a 20s moving window

### File Guide:
- Proj_2_File_1_Tyendinaga_Updated.ipynb
  - Developed using Grilla data for Tyendinaga
- hwy15 folder:
  - Developed using Grilla data for Highway 15
  - file 1: hwy15_stft_cwt.ipynb
    - Plots raw data
    - Plots detrended, normalized, shifted data
    - Plots tapered data with Hann window
    - Plots short-time fourier transform spectrograms
    - Plots continuous wavelet transform scalograms with the Morlet wavelet
  - file 2: hwy15_hvsr_fft_updates.ipynb
    - Fast Fourier transform plots
      - Frequency bin averaging was used to reduce frequency resolution
    - Power spectral density plots 
    - Horizontal-to-vertical spectral ratio based on FFT and PSD
