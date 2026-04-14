### Save Plots as PDF or JPG:
#### PDF
- Method: PDFPages from matplotlib.backends.backend_pdf
  - Successful method for saving output plots as PDF files, provided the file was not too large
  - Continuous wavelet transform plots were best saved as JPG files
- For full example usage, see the "Drone_With_Without_Payload" file in the Project_3_Drone_Data folder
#### JPG
- Method: plt.savefig() from matplotlib.pyplot imported as plt, specifying the file extension as '.jpg'
  - E.g. plt.savefig('CWT_difference_plot.jpg')
- For full example usage, see the "Drone_With_Without_Payload" file in the Project_3_Drone_Data folder

### Export Computed Values:
- Goal: export all computed values to an organized folder
- Method: a series of helper functions used at the END of a jupyter notebook, once all above cells have been run
  - Helper 1: creates a dictionary at "path" and returns the path string
  - Helper 2: writes a given real-valued array to a plain text file (.txt) with column headers
  - Helper 3: writes an array (can be complex) to a .npy file
- For full example usage, see the last cell in the "Drone_With_Without_Payload" file in the Project_3_Drone_Data folder
