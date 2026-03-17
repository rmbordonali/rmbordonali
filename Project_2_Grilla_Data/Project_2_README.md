### Project Description:
This project builds on Project 1 with a focus on passive seismics. This project was created using data downloaded from TROMINO GRILLA software.

### Code Summary:
- Linearly detrending data
- Normalizing data
- Shifting data to zero mean
- Subsampling data
- Tapering data with Hann window
- Fast Fourier transform (FFT) spectra
- Power spectral density plots with Welch's method
- Horizontal-to-vertical spectral ratio (HVSR)
- Short time Fourier transform (STFT) spectrograms with a 20s moving window
- Continuous wavelet transform scalograms with the Morlet wavelet

### File Guide:
- Tyendinaga folder:
  - Developed using Grilla data for Tyendinaga
  - Plots raw data
  - Plots detrended, normalized, shifted data
  - Plot subsampled data
  - Plots tapered data with Hann window
  - Plots tapered/subsampled data
  - Fast Fourier transform (FFT) plots
    - Plots averaged frequency spectrum
  - Power spectral density (PSD) plots
  - Horizontal-to-vertical spectral ratio based on FFT and PSD
  - Function to convert cell outputs and markdown to HTML file
    - Use print to PDF (e.g. Ctrl+P) to save as PDF file
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

  ### General Notes:
  - This project was developed using Jupyter Notebook with Python version 3.12.9
    - pandas version: 2.2.2
    - numpy version: 1.26.4
    - scipy version: 1.16.3 
