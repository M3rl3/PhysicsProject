#include "Vector3.h"

//Default constructor
Vector3::Vector3() /*: Vector3(0.f)*/ {
    this->x = 0.f;
    this->y = 0.f;
    this->z = 0.f;
}

//Parameterized constructor
Vector3::Vector3(float yes) /*: Vector3(yes, yes, yes)*/ {
    this->x = yes;
    this->y = yes;
    this->z = yes;
}

//Overloaded constructor
Vector3::Vector3(float x, float y, float z) /*: x(x), y(y), z(z)*/ {
    this->x = x;
    this->y = y;
    this->z = z;
}

//Copy Constructor
Vector3::Vector3(const Vector3& ass) {
    this->x = ass.x;
    this->y = ass.y;
    this->z = ass.z;
}

//Destructor
Vector3::~Vector3() {

}

//Assignment Overload
Vector3 Vector3::operator=(const Vector3 ass) {
    x = ass.x;
    y = ass.y;
    z = ass.z;
    return ass;
}

//Addition Overload
Vector3 Vector3::operator+(const Vector3 ass) {
    return Vector3(x + ass.x, y + ass.y, z + ass.z);
}

//Subtraction Overload
Vector3 Vector3::operator-(const Vector3 ass) {

    return Vector3(x - ass.x, y - ass.y, z - ass.z);
}

//Multiplication Overload
Vector3 Vector3::operator*(float ass) {
    return Vector3(x * ass, y * ass, z * ass);
}

//Division Overload
Vector3 Vector3::operator/(const float& ass) {
    return Vector3(x / ass, y / ass, z / ass);
}

//Insertion Overload
std::ostream& operator<<(std::ostream& out, Vector3& v1) {
    out << "\nVector3(" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;
    return out;
}

//Adds current vector to a scaled vector
void Vector3::scalevector(Vector3& ass, float scalar) {
    *this = *this + ass * scalar;
}

//Vector Magnitude
float Vector3::magnitude() {
    float result;
    result = sqrt(x * x + y * y + z * z);
    return result;
}

//Invert the vector
Vector3 Vector3::invert(Vector3& temp) {

    //return Vector3(x, y, z) * -1.0f;
    temp.x = temp.x * -1.0f;
    temp.y = temp.y * -1.0f;
    temp.z = temp.z * -1.0f;
    return (temp);
}

//Normalize the vector
void Vector3::normal() {
    float result = magnitude();

    x = x / result;
    y = y / result;
    z = z / result;
}