typedef struct {
  float x;
  float y;
  float z;
} Vec3;

typedef struct {
  float a;
  float b;
  float c;
  float d;
} Vec4; // == LQuaternionf

typedef struct {
   float _data[9];
} Mat3;

typedef struct {
   float _data[16];
} Mat4;
