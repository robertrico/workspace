/* This is the calc object found in the main program */

import java.util.*;
import java.text.*;
//((x * 100) + 0.5)) / 100; [0.000 rounding math]
public class InputCalc {
	private static DecimalFormat decForm = new DecimalFormat("##0.000");
	public String getMean(double [] data){
		double total=0;
		for (int i=0;i<data.length;i++){
			total+=data[i];
		}
	return decForm.format(total/data.length);
		
	}
	public String getMedian(double [] data){
		Arrays.sort(data);
		double median;
		if (data.length % 2 == 0)
		    median = ((double)data[data.length/2] + 
		    						 (double)data[data.length/2 - 1])/2;
		else
		    median = (double) data[data.length/2];
		return decForm.format(median);
	}
	public String getMax(double [] data){
		Arrays.sort(data);
		return decForm.format(data[data.length-1]);
	}
	public String getMin(double [] data){
		Arrays.sort(data);
		return decForm.format(data[0]);
	}
	public String getMode(double [] data){
		double maxVal = -1;
	    int hiCount = 0;
	    for(int i = 0; i < data.length; i++) {
	    	int count = 0; // count number of times data[i] has occurred
	        for(int j = 0; j < data.length; j++) {
	            if(data[j] == data[i]) {
	                count++;
	            }
	        }
	        	if(count > hiCount) { // record the highest count
	            maxVal = data[i];
	            hiCount = count;
	        	}
	    }
	    return decForm.format(maxVal);
	}
	
	public String getStDev(double[] data){
	    double sum = 0;
	    for(int i = 0; i<data.length; i++){
	        sum = sum + data[i];
	    }
	    double mean = sum/data.length;
	    double num = 0;
	    for(int j = 0; j<data.length;j++){
	        num +=Math.pow((data[j] - mean),2);
	    }
	    return decForm.format(Math.sqrt(num/(data.length-1)));
	}
}
