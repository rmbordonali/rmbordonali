### Project Description:
This project uses Python to create various plots for the purpose of analyzing time series data. Daily mean water level data for Toronto (1960-2024) was used when creating this project, as well as drone audio data.

### Code Summary:
- Linearly detrending data
- Normalizing data
- Shifting data to zero mean
- Subsampling data
- Tapering data with Hann window
- Adding sine waves to data
- Fast Fourier transform spectra
- Continuous wavelet transform scalograms with Morlet wavelet
- Histograms and statistics for plots
- Interactive Plotly plots

### File Guide:
- Proj_1_Ver_4_File_1: Water level data part 1
  - Includes interactive plotly plots
    - Raw data
    - Detrended, normalized, shifted data
    - Tapered and subsampled data
- Proj_1_Ver_4_File_2: Water level data part 2
  - Adding sine waves to the data
  - Original fast Fourier transform code
    - Frequency resolution not reduced
  - Original continuous wavelet transform scalogram code
    - Recommended to use a more recent project file for CWT plots 
- Proj_1_Part_2: Drone audio data

### General Notes:
- More recently updated versions of my code (e.g. for FFT and CWT plots) can be found in more recent project folders
