#ifndef AXLE_MATRIX_HPP
#define AXLE_MATRIX_HPP

#include "Core/Errors.hpp"
#include <array>
#include <iostream>
#include <string>

namespace Axle::Math {

template <unsigned int dim> class Matrix {
private:
  std::array<float, (size_t)dim * dim> data;

public:
  // ╔══════════════════════════════════╗
  // ║ -> Constructor
  // ╚══════════════════════════════════╝

  Matrix()
  {
    static_assert( dim == 2 || dim == 3 || dim == 4,
                   "Unsupported matrix size. Only 2x2, 3x3, and 4x4 matrices "
                   "are supported." );
    data.fill( 0.0F );
  }

  Matrix( float diag )
  {
    static_assert( dim == 2 || dim == 3 || dim == 4,
                   "Unsupported matrix size. Only 2x2, 3x3, and 4x4 matrices "
                   "are supported." );
    data.fill( 0.0F );
    for ( unsigned int i = 0; i < dim; i++ ) {
      data[i * dim + i] = diag;
    }
  }

  Matrix( std::array<float, (size_t)dim * dim> data ) : data( data ) {}

  // ╔══════════════════════════════════╗
  // ║ -> Accessors
  // ╚══════════════════════════════════╝

  // "at" accessor for getting and setting values

  [[nodiscard]] float at( unsigned int row, unsigned int col ) const
  {
    if ( row >= dim || col >= dim ) {
      throw Core::IndexOutOfBoundsError( 0, dim );
    }
    return data[col * dim + row];
  }

  float& at( unsigned int row, unsigned int col )
  {
    if ( row >= dim || col >= dim ) {
      throw Core::IndexOutOfBoundsError( 0, dim );
    }
    return data[col * dim + row];
  }

  // ╔══════════════════════════════════╗
  // ║ -> Utils
  // ╚══════════════════════════════════╝

  [[nodiscard]] std::string toString() const
  {
    std::string result;
    for ( unsigned int i = 0; i < dim; i++ ) {
      for ( unsigned int j = 0; j < dim; j++ ) {
        result += std::to_string( data[j * dim + i] ) + " ";
      }
      result += "\n";
    }
    return result;
  }

  // ╔══════════════════════════════════╗
  // ║ -> Math
  // ╚══════════════════════════════════╝

  [[nodiscard]] float det() const
  {
    if constexpr ( dim == 2 ) {
      return data[0] * data[3] - data[1] * data[2];
    }
    else if constexpr ( dim == 3 ) {
      return data[0] * data[4] * data[8] + data[1] * data[5] * data[6] +
             data[2] * data[3] * data[7] - data[2] * data[4] * data[6] -
             data[1] * data[3] * data[8] - data[0] * data[5] * data[7];
    }
    else if constexpr ( dim == 4 ) {
      // We will use the method of minors to calculate the determinant
      // we develop along the first column
      float result = 0;
      for ( unsigned int i = 0; i < 4; i++ ) {
        // Step 1 : Get the submatrix
        Matrix<dim - 1> submatrix = this->submatrix( 0, i );
        // Step 2 : Apply the cofactor sign
        // Step 3 : Multiply by the determinant of the submatrix
        // Step 4 : Add the result to the determinant
        result += ( submatrix.det() * ( i % 2 == 0 ? 1 : -1 ) ) * data[i];
      }
      return result;
    }
  };

  // Get the submatrix of the current matrix
  Matrix<dim - 1> submatrix( unsigned int row, unsigned int col ) const
  {
    // Assert that the matrix is 3x3 or 4x4
    static_assert( dim == 3 || dim == 4,
                   "Unsupported matrix size. Only 3x3 and 4x4 matrices are "
                   "supported." );

    // Check if the row and column are within the matrix bounds
    if ( row >= dim || col >= dim ) {

      throw Core::IndexOutOfBoundsError( 0, dim );
    }
    Matrix<dim - 1> result;
    unsigned int resultRow = 0;
    for ( unsigned int i = 0; i < dim; i++ ) {
      if ( i == row ) {
        continue;
      }
      unsigned int resultCol = 0;
      for ( unsigned int j = 0; j < dim; j++ ) {
        if ( j == col ) {
          continue;
        }
        result.at( resultRow, resultCol ) = data[j * dim + i];
        resultCol++;
      }
      resultRow++;
    }
    return result;
  }

  // Invert the matrix
  Matrix<dim> invert() const
  {
    // Check if the matrix is invertible
    float determinant = det();
    if ( determinant == 0 ) {
      throw Core::MatrixNonInvertibleError();
    }

    Matrix<dim> result;
    // We will use the formula for the inverse of a 2x2 matrix
    if constexpr ( dim == 2 ) {
      result.at( 0, 0 ) = data[3] / determinant;
      result.at( 0, 1 ) = -data[1] / determinant;
      result.at( 1, 0 ) = -data[2] / determinant;
      result.at( 1, 1 ) = data[0] / determinant;
      return result;
    }
    else {
      // For 3x3 and 4x4 matrices, we will use the method of minors
      // Because we used raw formulas for the determinant, this function
      // is non-recursive and should be reasonably fast
      Matrix<dim> result;
      for ( unsigned int row = 0; row < dim; row++ ) {
        for ( unsigned int col = 0; col < dim; col++ ) {
          // Step 1 : Get the submatrix
          Matrix<dim - 1> submatrix = this->submatrix( row, col );
          // Step 2 : Apply the cofactor sign
          // Step 3 : Multiply by -1 if the sum of the row and column is odd
          // to get the cofactor
          // Step 4 : Transpose the matrix (swap the row and column) to get the
          // adjugate matrix
          // Step 5 : Divide by the determinant to get the inverse
          float tmpResult =
              ( submatrix.det() * ( ( row + col ) % 2 == 0 ? 1 : -1 ) ) /
              determinant;
          result.at( col, row ) = tmpResult;
        }
      }
      return result;
    }
  }
};

// Aliases for supported matrix types
using Mat2 = Matrix<2>;
using Mat3 = Matrix<3>;
using Mat4 = Matrix<4>;

} // namespace Axle::Math

#endif // AXLE_MATRIX_HPP
