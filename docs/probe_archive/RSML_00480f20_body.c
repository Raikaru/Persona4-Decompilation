// FUN_00480F20 NONMATCHING
void func_00480f20(void* param_1, void* param_2)
{
    PrimInterpData* out = (PrimInterpData*)param_1;
    const PrimInterpData* in = (const PrimInterpData*)param_2;
    volatile /* Removing this qualifier worsens func_00480f20 (NONMATCHING nd237 -> NONMATCHING nd295, size 404 -> 364) - measured. */ f32 saved[4];
    f32 inY;
    f32 inX;
    f32 inZ;
    f32 inW;
    f32 norm;
    f32 inverse;
    f32 ax;
    f32 ay;
    f32 az;
    f32 aw;

    ax = out->quat.x; ay = out->quat.y; az = out->quat.z; aw = out->quat.w;
    saved[0] = ax; saved[1] = ay; saved[2] = az; saved[3] = aw;
    inY = in->quat.y; inX = in->quat.x; inZ = in->quat.z; inW = in->quat.w;
    norm = inY * inY + inX * inX + inZ * inZ + inW * inW;
    if (norm > 0.0f) { inverse = 1.0f / norm; inW = inW * inverse; inverse = -inverse; inX = inX * inverse; inY = inY * inverse; inZ = inZ * inverse; }
    ay = saved[1]; az = saved[2]; aw = saved[3]; ax = saved[0];
    out->quat.w = inW * aw - (inY * ay + inX * ax + inZ * az);
    out->quat.x = inZ * ay - inY * az;
    out->quat.y = inX * az - inZ * ax;
    out->quat.z = inY * ax - inX * ay;
    out->quat.x = out->quat.x + ax * inW; out->quat.y = out->quat.y + ay * inW; out->quat.z = out->quat.z + az * inW;
    out->quat.x = out->quat.x + inX * aw; out->quat.y = out->quat.y + inY * aw; out->quat.z = out->quat.z + inZ * aw;
    out->values[0] -= in->values[0]; out->values[1] -= in->values[1]; out->values[2] -= in->values[2];
    out->values[3] -= in->values[3]; out->values[4] -= in->values[4]; out->values[5] -= in->values[5];
}
