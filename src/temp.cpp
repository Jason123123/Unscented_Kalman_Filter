/* Generate sigma points */
  MatrixXd Xsig = MatrixXd(n_x_, n_x_ * 2 + 1);
  // calculate square root of P
  MatrixXd A = P_.llt().matrixL();
  //set first column of sigma point matrix
  Xsig.col(0)  = x_;

  //set remaining sigma points
  for (int i = 0; i < n_x_; i++)
  {
    Xsig.col(i+1)     = x_ + sqrt(lambda_ + n_x_) * A.col(i);
    Xsig.col(i+1+n_x) = x_ - sqrt(lambda_ + n_x_) * A.col(i);
  }