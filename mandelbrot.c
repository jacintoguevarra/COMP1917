int escapeSteps (double x, double y){

//xn = xn+1 + c
    double xn = 0;
    double yn = 0;
    int iterations = 0;
    double temp = 0;
    while( ((xn*xn + yn*yn) < 4) && (iterations < MAX_ITERATIONS)){
           temp = (xn*xn) - (yn*yn) + x;
           yn = 2*xn*yn + y;
           xn = temp;
           iterations = iterations + 1;
    }
return iterations;
}