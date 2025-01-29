#ifndef QUATERNION_H
#define QUATERNION_H

#include <cmath>

// ref: https://youtu.be/bKd2lPjl92c?si=JlkOGSgsGfVbq4o2
struct Quaternion {
    double w, x, y, z;

    // Quaternion multiplication
    Quaternion operator*(const Quaternion& q) const {
        return {
            w * q.w - x * q.x - y * q.y - z * q.z,
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w
        };
    }

    // Quaternion * Scalar
    Quaternion operator*(double scalar) const {
        return {w * scalar, x * scalar, y * scalar, z * scalar};
    }

    // Scalar * Quaternion (friend function allows left-hand scalar)
    friend Quaternion operator*(double scalar, const Quaternion& q) {
        return {q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar};
    }

    // addition
    Quaternion operator+(const Quaternion& q) const {
        return {w + q.w, x + q.x, y + q.y, z + q.z};
    }

    // Conjugate of a quaternion
    Quaternion conjugate() const {
        return {w, -x, -y, -z};
    }

    Quaternion normalize() const {

    }
};

// wx, wy, wz can be obtained from gyroscope
Quaternion updateQuaternion(const Quaternion& q, double wx, double wy, double wz, double dt) {
    // Convert angular velocity to a quaternion (pure quaternion, w = 0)
    Quaternion omega = {0, wx, wy, wz};

    // Update quaternion: q_next = q + 0.5 * omega * q * dt (Euler integration)
    Quaternion q_next = q + 0.5 * omega * q * dt;

    // Normalize the quaternion to prevent drift
    return q_next.normalize();
}

#endif