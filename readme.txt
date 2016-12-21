/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name:SHI Zhenmei             
Login:zshiad            
Hours to complete assignment (optional):16



/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
Exact all four-points-group and check whether they are on the same line.
Only use get function of the Point.


/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/
For each point calculate the angle with each other. Angle is a type which have 
two int p and q, and gcd(p,q)==1. Then sort the angle. For each point, find same
angle numbers, and check whether there is a 4-points-line and record it.

Use a vector spcae to rector angle.

Every time record a line. Use graph theory draw an edge between two points
(2D array). Before record a line, we need first check whether there is an edge.



/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------msec
     10        0              0 
     20        4              0
     40       18              0
     80       347             1 
    100       753             2
    150       4054            2
    200      12721            7           
    400      209048          13 
   1000      5357670         131
   2000                      340
   4000                      1008
  10000                      6313


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute:2*10^8 years
Sorting:2 hours



/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute:O(N^4)
Sorting:O(N^2logN)
For Brute, there are four loops. Easily know O(N^4).
For Sorting, need O(N) for each point to calculate the angle. All points need 
O(N^2). And sorting need O(NlogN) for each point. All points need O(N^2logN).
Totally need O(N^2logN).


/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
NA


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/
NA


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
NA



/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
QT is so tedious. But it is really powerful.

