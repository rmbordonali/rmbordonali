### Project Description:
- Mika's vibrometer data was run through my program and plots were created for multiple measurement cases:
  - Case 1: Car off
  - Case 2: Car on
  - Case 3: Car on, music playing
  - Case 4: Revving car engine

### Code Summary:
- Raw data plots
- Linearly detrending and shifting data to zero mean
- Tapering data with a Hann window
- Subsampling data
- Fast Fourier transform
  - Averaged frequency spectrum
- Power spectral density
- Continuous wavelet transform with Morlet wavelet

### File Guide:
- "Car_Off_Vibrometer_Plots.ipynb"
- "Car_On_Vibrometer_Plots.ipynb"
- "Revving_Car_Engine_Vibrometer_Plots.ipynb"
 
### General Notes:
- The "Car_On_Vibrometer_Plots.ipynb" file contains plots for both Case 2 and Case 3
- This project was developed using Jupyter Notebook with Python version 3.12.9
    - pandas version: 2.2.2
    - numpy version: 1.26.4
    - scipy version: 1.16.3
    - matplotlib version: 3.8.4
    - ssqueezepy version: 0.6.6
    - sklearn version: 1.4.2
