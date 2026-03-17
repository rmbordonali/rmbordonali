### Project Description:
Goals for this project include completing wavelet analysis and fourier analysis for drone data.

### Code Summary:
- Raw data plots
- Linearly detrending, normalizing and shifting data to zero mean
- Tapering data with the Hann window
- Fast Fourier Transform
  - Averaged frequency spectrum
- Power spectral density with Welch's method
- Continuous wavelet transform with the Morlet wavelet
  - Difference scalograms (i.e. CWT1 - CWT2)

### File Guide:
- Drone with & without payload: "Drone_With_Without_Payload.ipynb"
  - Developed using audio files with/without MagArrow payload
  - Raw data plots
  - Detrended, normalized, shifted data plots
  - Joined plot for data with payload to data without payload
  - Trimming data
  - Tapered data plots
  - Fast Fourier transform averaged frequency spectrum
  - Power spectral density plots
  - Continuous wavelet transform scalograms and difference plot
  - Option to save cell outputs and markdown as HTML file with save_notebook function
    - Convert to PDF file with print to PDF (e.g. Ctrl + P)
