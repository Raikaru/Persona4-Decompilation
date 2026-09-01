void func_001bf5e0(u8 *arg0)
{
    u8 *action;
    u8 *unit;
    u8 *unit2;
    f32 frame[4];
    f32 center1[3];
    f32 center2[3];
    f32 dir[3];
    f32 firstPos[3];
    f32 secondPos[3];
    f32 blendPos[4];
    f32 work[4];
    f32 work2[4];
    f32 work3[4];
    f32 angle;
    f32 ratio;
    f32 scale;
    f32 dist;
    f32 temp;

    action = *(u8 **)(arg0 + 0xE0);
    unit = *(u8 **)(action + 0x30);
    unit2 = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001bd560(frame, arg0 + 0x9C);
    func_00195850(unit, center1);
    func_00195850(unit2, center2);
    center1[1] = 0.0f + center1[1] + *(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C) * *(f32 *)(iGpffffb3ac + 0));
    if (center1[1] < 100.0f) center1[1] = 100.0f;
    dir[0] = frame[0] - center1[0]; dir[1] = frame[1] - center1[1]; dir[2] = frame[2] - center1[2];
    dist = func_003e4180(dir) * *(f32 *)(iGpffffb3ac + 0);
    work[2] = dir[0]; work[3] = dir[2]; func_003e41e0(work + 2, work + 2);
    center2[1] = center1[1];
    dir[0] = center2[0] - center1[0]; dir[1] = center2[1] - center1[1]; dir[2] = center2[2] - center1[2];
    func_003e40b0(dir, dir); work[0] = dir[0]; work[1] = dir[2];
    if (dir[0] * work[2] + dir[2] * work[3] < 0.0f) { dir[0] = -dir[0]; dir[1] = -dir[1]; dir[2] = -dir[2]; }
    scale = *(f32 *)(unit2 + 0x90) * *(f32 *)(unit2 + 0x2C);
    secondPos[0] = dir[0] * scale; secondPos[1] = dir[1] * scale; secondPos[2] = dir[2] * scale;
    firstPos[0] = center1[0] + secondPos[0]; firstPos[1] = center1[1] + secondPos[1]; firstPos[2] = center1[2] + secondPos[2];
    scale = 5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    dir[0] *= scale; dir[1] *= scale; dir[2] *= scale;
    secondPos[0] = center1[0] + dir[0]; secondPos[1] = center1[1] + dir[1]; secondPos[2] = center1[2] + dir[2];
    secondPos[1] = 0.0f + center2[1] + 0.5f * (*(f32 *)(unit2 + 0x8C) * *(f32 *)(unit2 + 0x2C));
    dir[0] = secondPos[0] - center1[0]; dir[1] = secondPos[1] - center1[1]; dir[2] = secondPos[2] - center1[2]; func_003e40b0(dir, dir);
    func_001bd780(work2, secondPos, firstPos, D_0060A0E0);
    angle = func_001ec2b0(frame + 3, work2);
    if (angle > *(f32 *)(iGpffffb3ac + 0)) {
        ratio = *(f32 *)(iGpffffb3ac + 0) / angle;
        func_003dcb40(blendPos, frame + 3, work2, 1, 0);
        if (ratio <= 0.0f) { work3[0]=frame[3]; work3[1]=frame[4]; work3[2]=frame[5]; work3[3]=frame[6]; }
        else if (1.0f <= ratio) { work3[0]=work2[0]; work3[1]=work2[1]; work3[2]=work2[2]; work3[3]=work2[3]; }
        else { scale = 1.0f - ratio; work3[0]=blendPos[0]*scale + blendPos[1]*ratio; work3[1]=blendPos[1]*scale + blendPos[2]*ratio; work3[2]=blendPos[2]*scale + blendPos[3]*ratio; work3[3]=blendPos[3]*scale + blendPos[0]*ratio; }
        func_003dcb40(dir, D_0060A100, 1, work3);
        secondPos[0] = firstPos[0] + dir[0]; secondPos[1] = firstPos[1] + dir[1]; secondPos[2] = firstPos[2] + dir[2];
        func_001bd780(work2, secondPos, firstPos, D_0060A0E0);
    }
    if (dist < 600.0f) dist = 600.0f;
    dir[0] *= dist; dir[1] *= dist; dir[2] *= dist;
    work[0] = firstPos[0] + dir[0]; work[1] = firstPos[1] + dir[1]; work[2] = firstPos[2] + dir[2];
    func_001bac20(arg0, frame, work, 1);
    func_001bbef0(arg0, 1.0f);
}
