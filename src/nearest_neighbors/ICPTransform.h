#pragma once
/*
This class implements an ICP point alignment from two set of points. 
It only implements the transformation part of a point-to-point ICP algorithm.
Means, the points in the input vectors points0 and points1 MUST be index aligned nearest neighbors
and come as Vector4f with [x,y, z, w] per point. 
All matrices are in Eigen-standard column major, with matrix to points from the left -> M p

Note, the class uses float, which reduces the precision if the point values are already numerically
small.

Usage:
Matrix4f Rt = ICPCorrection::Compute(points0, points1);

Rafael Radkowski
Iowa State University
rafael@iastate.edu
Nov. 17, 2017
*/



// stl
#include <iostream>
#include <vector>
#include <numeric>

// Eigen 3
#include <Eigen/Dense>


using namespace Eigen;
using namespace std;

class ICPTransform
{
public:

	/*
	Computes the difference between two set of points
	@param points0 - a vector with Eigen::Vec4 points, [x, y, z, w]
	@param points1 - a vector with Eigen::VEc4 points,  [x, y, z, w]
	@return the rotation and translation difference between those points as 
		4x4 matri in homogenous coordinate frames.
	*/
	static  Matrix4f Compute(vector<Vector4f>& points0, vector<Vector4f>& points1);


private:

	/*


	/*
	Calculates the translation delta between both point sets as mean.
	@param pVec0 - first point array, each element needs to be a vector4 [[x, y, z, w], [x, y, z, w], ...]
	*/
	static Vector3f CalculateTranslation(vector<Vector3f>& pVec0, vector<Vector3f>& pVec1);

	/*
	Check the root mean square error between the two points sets. 
	Do not forget to translate the reference point set before checking. 
	@param pVec0 - first point array, each element needs to be a vector4 [[x, y, z, w], [x, y, z, w], ...]
	*/
	static float CheckRMS(vector<Vector3f>& pVec0, vector<Vector3f>& pVec1);


};