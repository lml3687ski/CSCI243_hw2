/**
 * @file stats.h
 * @brief Interface for the grade-statistics module (Homework 2). You implement
 *        these three functions in stats.c.
 *
 * STUDENT TODO: complete the documentation comments below (add @param and
 * @return descriptions where marked) as part of this assignment.
 *
 * @author Logan Larocque (lml3687@rit.edu)
 * @course CSCI-243 Homework 2 (Statistics)
 */
#ifndef STATS_H
#define STATS_H

/** Number of plus/minus letter-grade buckets in the histogram. */
#define NUM_GRADES 10

/**
 * Compute the arithmetic mean (average) of a data set.
 * STUDENT TODO: document @param n, @param data, and @return.
 * @param n The number of grades input by the user as an integer
 * @param data An integer array of all of the grades
 * @return Returns the mean of all grades in the data array as an integer
 */
double average(int n, const int data[]);

/**
 * Compute the sample standard deviation: sqrt( sum((x - mean)^2) / (n - 1) ).
 * STUDENT TODO: document @param n, @param data, @param mean, and @return,
 * including the value returned when n < 2.
 * @param n The integer number of grades input by the user
 * @param data An integer array of all grades input by the user
 * @param mean The mean value of the grades (int)
 * @return 0.0 if n < 2, Otherwise returns the standard deviation of the data
 */
double std_dev(int n, const int data[], double mean);

/**
 * Print the plus/minus grade histogram to standard output (see the manual for
 * the exact grade ranges and output format).
 * STUDENT TODO: document @param n and @param data.
 * @param n Integer number of grades input by the user
 * @param data Integer array of grades
 */
void histogram(int n, const int data[]);

#endif /* STATS_H */
