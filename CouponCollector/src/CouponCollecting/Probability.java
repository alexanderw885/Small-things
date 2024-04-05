/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CouponCollecting;

import static java.lang.Math.sqrt;
import java.util.Random;

/**
 *
 * @author alexa
 */
public class Probability {

    /**
     * A brute force algorithm to solve the coupon collector's problem
     * @param coupons number of "coupons" to collect
     * @param tries how many times to run the loop. Larger number gives more accurate result
     * @return out[1] contains observed mean, out[2] contains observed s.d.
     */
    static double[] meanSD(int coupons, int tries) {
        Random rand = new Random();
        int[] results = new int[tries];

        for (int i = 0; i < tries; i++) {
            //setup for each loop
            boolean[] picked = new boolean[coupons];
            int attempts = 0;
            boolean success = false;

            //counts up each loop, only breaks once all options4ave been picked
            while (!success) {
                attempts++;
                int check = rand.nextInt(0, coupons);
                picked[check] = true;

                success = true;
                for (int j = 0; j < coupons; j++) {
                    if (picked[j] == false) {
                        success = false;
                    }
                }
            }
            results[i] = attempts;
            //System.out.println(attempts);
        }
        //observed mean/standard deviation
        double mean = 0;
        for (int i = 0; i < results.length; i++) {
            mean += results[i];
        }
        mean /= tries;

        double sd = 0;
        for (int i = 0; i < results.length; i++) {
            sd += Math.abs(results[i] - mean);
        }
        sd /= tries;
        double[] out = {mean, sd};
        return out;
    }

    static double[] calculateCI(double mean, double sd, double alpha, int tries) {

        double cv = CritVal(alpha / 2);

        double ese = sd / sqrt(tries);

        double[] out = {mean - (cv * ese), mean + (cv * ese)};
        return out;
    }

    private static double CritVal(double alpha) {
        double underCurve = 0.5;
        double delta = 0.0001;
        double position = 0;

        while (Math.abs((1 - underCurve) - alpha) > 0.0001) {
            if ((1 - underCurve) < alpha) {
                position -= delta;
                underCurve -= (1 / sqrt(2 * Math.PI)) * Math.pow(Math.E, -0.5 * Math.pow(position, 2)) * delta;
            } else {
                position += delta;
                underCurve += (1 / sqrt(2 * Math.PI)) * Math.pow(Math.E, -0.5 * Math.pow(position, 2)) * delta;
            }
            //System.out.println("pos: "+position);
        }
        return position;
    }
}
