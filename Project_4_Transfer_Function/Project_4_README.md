### Project Description:
This project is focussed on using experimental data to estimate transfer functions.

### Code Summary:
- Load and plot data
- Trimming data, resampling data
- Detrending and shifting data to zero mean
- Tapering
- Cross correlation
- Fast Fourier transform
- Power spectral density
- Transfer function estimation

### File Guide:
- Transfer Function with Square Wave-GitHub.ipynb
  - Uses vibrometer measurements of a speaker playing a square wave to obtain transfer function estimates 
  - includes all of the points mentioned under Code Summary
- updated-vibrometer-experiment-GitHub.ipynb
  - includes all points under Code Summary with the exception of cross correlation
  - Uses vibrometer measurements of glass in front of a speaker which plays a square wave
    - Also includes microphone recordings made with rode wireless pro microphones
- Progress Slides 2
  - A powerpoint with past update slides showing sample plots/results of the transfer function estimation
    - e.g. Spikes in the coherence plot at harmonic values of the square wave played (experiment setup with glass in front of speaker)
    
### General Notes:
- This project was developed using Jupyter Notebook with Python version 3.12.9
  - pandas version: 2.2.2
  - numpy version: 1.26.4
  - scipy version: 1.16.3
  - matplotlib version: 3.8.4
- The transfer function estimation code is at the end of the Jupyter Notebooks
  - This is the main Python function that differs from those in previous project files
- To use the Jupyter notebooks directly, the data loaded will have to be modified to fit your data files
  - E.g. titles and the amount of measurements may need to be manually adjusted, resampling may also need to be adjusted based on the sample rate of your data
