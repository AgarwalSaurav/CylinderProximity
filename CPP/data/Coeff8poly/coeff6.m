(* Created by Wolfram Mathematica 9.0 : www.wolfram.com *)
(4*Power(q0,4) + 8*Power(q0,2)*Power(q1,2) + 4*Power(q1,4) - 
     8*Power(q0,2)*Power(q2,2) + 8*Power(q1,2)*Power(q2,2) + 
     4*Power(q2,4) - 32*q0*q1*q2*q3 + 8*Power(q0,2)*Power(q3,2) - 
     8*Power(q1,2)*Power(q3,2) + 8*Power(q2,2)*Power(q3,2) + 4*Power(q3,4))*
   Power(tx,4) + Power(r1,2)*((-64*Power(q0,4)*Power(q1,4) + 
        320*Power(q0,4)*Power(q1,2)*Power(q2,2) - 
        64*Power(q0,4)*Power(q2,4) + 896*Power(q0,3)*Power(q1,3)*q2*q3 - 
        896*Power(q0,3)*q1*Power(q2,3)*q3 + 
        320*Power(q0,2)*Power(q1,4)*Power(q3,2) - 
        2048*Power(q0,2)*Power(q1,2)*Power(q2,2)*Power(q3,2) + 
        320*Power(q0,2)*Power(q2,4)*Power(q3,2) - 
        896*q0*Power(q1,3)*q2*Power(q3,3) + 
        896*q0*q1*Power(q2,3)*Power(q3,3) - 64*Power(q1,4)*Power(q3,4) + 
        320*Power(q1,2)*Power(q2,2)*Power(q3,4) - 
        64*Power(q2,4)*Power(q3,4))*Power(r2,2) + 
     (4*Power(q0,4) + 8*Power(q0,2)*Power(q1,2) + 4*Power(q1,4) - 
        8*Power(q0,2)*Power(q2,2) + 8*Power(q1,2)*Power(q2,2) + 
        4*Power(q2,4) - 32*q0*q1*q2*q3 + 8*Power(q0,2)*Power(q3,2) - 
        8*Power(q1,2)*Power(q3,2) + 8*Power(q2,2)*Power(q3,2) + 
        4*Power(q3,4))*Power(tx,2) + 
     (-64*Power(q0,2)*q1*q2 - 64*q0*Power(q1,2)*q3 + 
        64*q0*Power(q2,2)*q3 + 64*q1*q2*Power(q3,2))*tx*ty + 
     (-16*Power(q0,2)*Power(q1,2) + 16*Power(q0,2)*Power(q2,2) + 
        64*q0*q1*q2*q3 + 16*Power(q1,2)*Power(q3,2) - 
        16*Power(q2,2)*Power(q3,2))*Power(ty,2)) + 
  Power(tx,3)*((32*Power(q0,2)*q1*q2 + 32*q0*Power(q1,2)*q3 - 
        32*q0*Power(q2,2)*q3 - 32*q1*q2*Power(q3,2))*ty + 
     (-16*Power(q0,3)*q2 + 16*q0*Power(q1,2)*q2 + 16*q0*Power(q2,3) - 
        16*Power(q0,2)*q1*q3 + 16*Power(q1,3)*q3 + 16*q1*Power(q2,2)*q3 - 
        16*q0*q2*Power(q3,2) - 16*q1*Power(q3,3))*tz) + 
  Power(tx,2)*((4*Power(q0,4) - 8*Power(q0,2)*Power(q1,2) + 
        4*Power(q1,4) + 8*Power(q0,2)*Power(q2,2) + 
        8*Power(q1,2)*Power(q2,2) + 4*Power(q2,4) + 32*q0*q1*q2*q3 + 
        8*Power(q0,2)*Power(q3,2) + 8*Power(q1,2)*Power(q3,2) - 
        8*Power(q2,2)*Power(q3,2) + 4*Power(q3,4))*Power(ty,2) + 
     (16*Power(q0,3)*q1 - 16*q0*Power(q1,3) - 16*q0*q1*Power(q2,2) - 
        16*Power(q0,2)*q2*q3 + 16*Power(q1,2)*q2*q3 + 16*Power(q2,3)*q3 + 
        16*q0*q1*Power(q3,2) - 16*q2*Power(q3,3))*ty*tz + 
     (16*Power(q0,2)*Power(q1,2) + 16*Power(q0,2)*Power(q2,2) + 
        16*Power(q1,2)*Power(q3,2) + 16*Power(q2,2)*Power(q3,2))*Power(tz,2)) \
+ Power(r2,2)*((-4*Power(q0,8) - 16*Power(q0,6)*Power(q1,2) - 
        24*Power(q0,4)*Power(q1,4) - 16*Power(q0,2)*Power(q1,6) - 
        4*Power(q1,8) + 16*Power(q0,6)*Power(q2,2) + 
        16*Power(q0,4)*Power(q1,2)*Power(q2,2) - 
        16*Power(q0,2)*Power(q1,4)*Power(q2,2) - 
        16*Power(q1,6)*Power(q2,2) - 24*Power(q0,4)*Power(q2,4) + 
        16*Power(q0,2)*Power(q1,2)*Power(q2,4) - 
        24*Power(q1,4)*Power(q2,4) + 16*Power(q0,2)*Power(q2,6) - 
        16*Power(q1,2)*Power(q2,6) - 4*Power(q2,8) + 
        64*Power(q0,5)*q1*q2*q3 + 128*Power(q0,3)*Power(q1,3)*q2*q3 + 
        64*q0*Power(q1,5)*q2*q3 - 128*Power(q0,3)*q1*Power(q2,3)*q3 + 
        128*q0*Power(q1,3)*Power(q2,3)*q3 + 64*q0*q1*Power(q2,5)*q3 - 
        16*Power(q0,6)*Power(q3,2) - 
        16*Power(q0,4)*Power(q1,2)*Power(q3,2) + 
        16*Power(q0,2)*Power(q1,4)*Power(q3,2) + 
        16*Power(q1,6)*Power(q3,2) + 
        16*Power(q0,4)*Power(q2,2)*Power(q3,2) - 
        352*Power(q0,2)*Power(q1,2)*Power(q2,2)*Power(q3,2) + 
        16*Power(q1,4)*Power(q2,2)*Power(q3,2) + 
        16*Power(q0,2)*Power(q2,4)*Power(q3,2) - 
        16*Power(q1,2)*Power(q2,4)*Power(q3,2) - 
        16*Power(q2,6)*Power(q3,2) + 128*Power(q0,3)*q1*q2*Power(q3,3) - 
        128*q0*Power(q1,3)*q2*Power(q3,3) + 
        128*q0*q1*Power(q2,3)*Power(q3,3) - 24*Power(q0,4)*Power(q3,4) + 
        16*Power(q0,2)*Power(q1,2)*Power(q3,4) - 
        24*Power(q1,4)*Power(q3,4) - 
        16*Power(q0,2)*Power(q2,2)*Power(q3,4) + 
        16*Power(q1,2)*Power(q2,2)*Power(q3,4) - 
        24*Power(q2,4)*Power(q3,4) + 64*q0*q1*q2*Power(q3,5) - 
        16*Power(q0,2)*Power(q3,6) + 16*Power(q1,2)*Power(q3,6) - 
        16*Power(q2,2)*Power(q3,6) - 4*Power(q3,8))*Power(tx,2) + 
     (-64*Power(q0,4)*Power(q1,2)*Power(q2,2) - 
        128*Power(q0,3)*Power(q1,3)*q2*q3 + 
        128*Power(q0,3)*q1*Power(q2,3)*q3 - 
        64*Power(q0,2)*Power(q1,4)*Power(q3,2) + 
        256*Power(q0,2)*Power(q1,2)*Power(q2,2)*Power(q3,2) - 
        64*Power(q0,2)*Power(q2,4)*Power(q3,2) + 
        128*q0*Power(q1,3)*q2*Power(q3,3) - 
        128*q0*q1*Power(q2,3)*Power(q3,3) - 
        64*Power(q1,2)*Power(q2,2)*Power(q3,4))*Power(ty,2) + 
     (64*Power(q0,5)*q1*Power(q2,2) - 
        64*Power(q0,3)*Power(q1,3)*Power(q2,2) - 
        64*Power(q0,3)*q1*Power(q2,4) + 
        128*Power(q0,4)*Power(q1,2)*q2*q3 - 
        128*Power(q0,2)*Power(q1,4)*q2*q3 - 
        64*Power(q0,4)*Power(q2,3)*q3 - 
        64*Power(q0,2)*Power(q1,2)*Power(q2,3)*q3 + 
        64*Power(q0,2)*Power(q2,5)*q3 + 
        64*Power(q0,3)*Power(q1,3)*Power(q3,2) - 
        64*q0*Power(q1,5)*Power(q3,2) - 
        64*Power(q0,3)*q1*Power(q2,2)*Power(q3,2) + 
        64*q0*Power(q1,3)*Power(q2,2)*Power(q3,2) + 
        128*q0*q1*Power(q2,4)*Power(q3,2) + 
        64*Power(q0,2)*Power(q1,2)*q2*Power(q3,3) + 
        64*Power(q1,4)*q2*Power(q3,3) - 
        64*Power(q0,2)*Power(q2,3)*Power(q3,3) + 
        64*Power(q1,2)*Power(q2,3)*Power(q3,3) + 
        64*q0*Power(q1,3)*Power(q3,4) - 
        128*q0*q1*Power(q2,2)*Power(q3,4) - 64*Power(q1,2)*q2*Power(q3,5))*
      ty*tz + (-16*Power(q0,6)*Power(q2,2) + 
        32*Power(q0,4)*Power(q1,2)*Power(q2,2) - 
        16*Power(q0,2)*Power(q1,4)*Power(q2,2) + 
        32*Power(q0,4)*Power(q2,4) - 
        32*Power(q0,2)*Power(q1,2)*Power(q2,4) - 
        16*Power(q0,2)*Power(q2,6) - 32*Power(q0,5)*q1*q2*q3 + 
        64*Power(q0,3)*Power(q1,3)*q2*q3 - 32*q0*Power(q1,5)*q2*q3 + 
        64*Power(q0,3)*q1*Power(q2,3)*q3 - 
        64*q0*Power(q1,3)*Power(q2,3)*q3 - 32*q0*q1*Power(q2,5)*q3 - 
        16*Power(q0,4)*Power(q1,2)*Power(q3,2) + 
        32*Power(q0,2)*Power(q1,4)*Power(q3,2) - 
        16*Power(q1,6)*Power(q3,2) - 
        32*Power(q0,4)*Power(q2,2)*Power(q3,2) + 
        64*Power(q0,2)*Power(q1,2)*Power(q2,2)*Power(q3,2) - 
        32*Power(q1,4)*Power(q2,2)*Power(q3,2) + 
        32*Power(q0,2)*Power(q2,4)*Power(q3,2) - 
        16*Power(q1,2)*Power(q2,4)*Power(q3,2) - 
        64*Power(q0,3)*q1*q2*Power(q3,3) + 
        64*q0*Power(q1,3)*q2*Power(q3,3) + 
        64*q0*q1*Power(q2,3)*Power(q3,3) - 
        32*Power(q0,2)*Power(q1,2)*Power(q3,4) + 
        32*Power(q1,4)*Power(q3,4) - 
        16*Power(q0,2)*Power(q2,2)*Power(q3,4) + 
        32*Power(q1,2)*Power(q2,2)*Power(q3,4) - 32*q0*q1*q2*Power(q3,5) - 
        16*Power(q1,2)*Power(q3,6))*Power(tz,2) + 
     tx*((-32*Power(q0,6)*q1*q2 - 64*Power(q0,4)*Power(q1,3)*q2 - 
           32*Power(q0,2)*Power(q1,5)*q2 + 64*Power(q0,4)*q1*Power(q2,3) - 
           64*Power(q0,2)*Power(q1,3)*Power(q2,3) - 
           32*Power(q0,2)*q1*Power(q2,5) - 32*Power(q0,5)*Power(q1,2)*q3 - 
           64*Power(q0,3)*Power(q1,4)*q3 - 32*q0*Power(q1,6)*q3 + 
           32*Power(q0,5)*Power(q2,2)*q3 + 
           384*Power(q0,3)*Power(q1,2)*Power(q2,2)*q3 - 
           32*q0*Power(q1,4)*Power(q2,2)*q3 - 
           64*Power(q0,3)*Power(q2,4)*q3 + 
           32*q0*Power(q1,2)*Power(q2,4)*q3 + 32*q0*Power(q2,6)*q3 - 
           32*Power(q0,4)*q1*q2*Power(q3,2) + 
           384*Power(q0,2)*Power(q1,3)*q2*Power(q3,2) + 
           32*Power(q1,5)*q2*Power(q3,2) - 
           384*Power(q0,2)*q1*Power(q2,3)*Power(q3,2) + 
           64*Power(q1,3)*Power(q2,3)*Power(q3,2) + 
           32*q1*Power(q2,5)*Power(q3,2) - 
           64*Power(q0,3)*Power(q1,2)*Power(q3,3) + 
           64*q0*Power(q1,4)*Power(q3,3) + 
           64*Power(q0,3)*Power(q2,2)*Power(q3,3) - 
           384*q0*Power(q1,2)*Power(q2,2)*Power(q3,3) + 
           64*q0*Power(q2,4)*Power(q3,3) + 
           32*Power(q0,2)*q1*q2*Power(q3,4) - 
           64*Power(q1,3)*q2*Power(q3,4) + 64*q1*Power(q2,3)*Power(q3,4) - 
           32*q0*Power(q1,2)*Power(q3,5) + 32*q0*Power(q2,2)*Power(q3,5) + 
           32*q1*q2*Power(q3,6))*ty + 
        (16*Power(q0,7)*q2 + 16*Power(q0,5)*Power(q1,2)*q2 - 
           16*Power(q0,3)*Power(q1,4)*q2 - 16*q0*Power(q1,6)*q2 - 
           48*Power(q0,5)*Power(q2,3) + 
           32*Power(q0,3)*Power(q1,2)*Power(q2,3) - 
           48*q0*Power(q1,4)*Power(q2,3) + 48*Power(q0,3)*Power(q2,5) - 
           48*q0*Power(q1,2)*Power(q2,5) - 16*q0*Power(q2,7) + 
           16*Power(q0,6)*q1*q3 + 16*Power(q0,4)*Power(q1,3)*q3 - 
           16*Power(q0,2)*Power(q1,5)*q3 - 16*Power(q1,7)*q3 - 
           176*Power(q0,4)*q1*Power(q2,2)*q3 + 
           160*Power(q0,2)*Power(q1,3)*Power(q2,2)*q3 - 
           48*Power(q1,5)*Power(q2,2)*q3 + 
           176*Power(q0,2)*q1*Power(q2,4)*q3 - 
           48*Power(q1,3)*Power(q2,4)*q3 - 16*q1*Power(q2,6)*q3 + 
           48*Power(q0,5)*q2*Power(q3,2) - 
           160*Power(q0,3)*Power(q1,2)*q2*Power(q3,2) + 
           176*q0*Power(q1,4)*q2*Power(q3,2) - 
           32*Power(q0,3)*Power(q2,3)*Power(q3,2) + 
           160*q0*Power(q1,2)*Power(q2,3)*Power(q3,2) - 
           16*q0*Power(q2,5)*Power(q3,2) + 48*Power(q0,4)*q1*Power(q3,3) - 
           32*Power(q0,2)*Power(q1,3)*Power(q3,3) + 
           48*Power(q1,5)*Power(q3,3) - 
           160*Power(q0,2)*q1*Power(q2,2)*Power(q3,3) + 
           32*Power(q1,3)*Power(q2,2)*Power(q3,3) - 
           16*q1*Power(q2,4)*Power(q3,3) + 48*Power(q0,3)*q2*Power(q3,4) - 
           176*q0*Power(q1,2)*q2*Power(q3,4) + 
           16*q0*Power(q2,3)*Power(q3,4) + 48*Power(q0,2)*q1*Power(q3,5) - 
           48*Power(q1,3)*Power(q3,5) + 16*q1*Power(q2,2)*Power(q3,5) + 
           16*q0*q2*Power(q3,6) + 16*q1*Power(q3,7))*tz)) + 
  r1*((8*Power(q0,4) + 16*Power(q0,2)*Power(q1,2) + 8*Power(q1,4) - 
        16*Power(q0,2)*Power(q2,2) + 16*Power(q1,2)*Power(q2,2) + 
        8*Power(q2,4) - 64*q0*q1*q2*q3 + 16*Power(q0,2)*Power(q3,2) - 
        16*Power(q1,2)*Power(q3,2) + 16*Power(q2,2)*Power(q3,2) + 
        8*Power(q3,4))*Power(tx,3) + 
     (-16*Power(q0,2)*q1*q2 - 16*q0*Power(q1,2)*q3 + 16*q0*Power(q2,2)*q3 + 
        16*q1*q2*Power(q3,2))*Power(ty,3) + 
     (8*Power(q0,3)*q2 - 8*q0*Power(q1,2)*q2 - 8*q0*Power(q2,3) + 
        8*Power(q0,2)*q1*q3 - 8*Power(q1,3)*q3 - 8*q1*Power(q2,2)*q3 + 
        8*q0*q2*Power(q3,2) + 8*q1*Power(q3,3))*Power(ty,2)*tz + 
     Power(tx,2)*((-32*Power(q0,2)*q1*q2 - 32*q0*Power(q1,2)*q3 + 
           32*q0*Power(q2,2)*q3 + 32*q1*q2*Power(q3,2))*ty + 
        (-16*Power(q0,3)*q2 + 16*q0*Power(q1,2)*q2 + 16*q0*Power(q2,3) - 
           16*Power(q0,2)*q1*q3 + 16*Power(q1,3)*q3 + 
           16*q1*Power(q2,2)*q3 - 16*q0*q2*Power(q3,2) - 16*q1*Power(q3,3))*
         tz) + Power(r2,2)*((-32*Power(q0,6)*Power(q1,2) - 
           64*Power(q0,4)*Power(q1,4) - 32*Power(q0,2)*Power(q1,6) + 
           32*Power(q0,6)*Power(q2,2) + 
           320*Power(q0,4)*Power(q1,2)*Power(q2,2) - 
           32*Power(q0,2)*Power(q1,4)*Power(q2,2) - 
           64*Power(q0,4)*Power(q2,4) + 
           32*Power(q0,2)*Power(q1,2)*Power(q2,4) + 
           32*Power(q0,2)*Power(q2,6) + 128*Power(q0,5)*q1*q2*q3 + 
           896*Power(q0,3)*Power(q1,3)*q2*q3 + 128*q0*Power(q1,5)*q2*q3 - 
           896*Power(q0,3)*q1*Power(q2,3)*q3 + 
           256*q0*Power(q1,3)*Power(q2,3)*q3 + 128*q0*q1*Power(q2,5)*q3 - 
           32*Power(q0,4)*Power(q1,2)*Power(q3,2) + 
           320*Power(q0,2)*Power(q1,4)*Power(q3,2) + 
           32*Power(q1,6)*Power(q3,2) + 
           32*Power(q0,4)*Power(q2,2)*Power(q3,2) - 
           2048*Power(q0,2)*Power(q1,2)*Power(q2,2)*Power(q3,2) + 
           32*Power(q1,4)*Power(q2,2)*Power(q3,2) + 
           320*Power(q0,2)*Power(q2,4)*Power(q3,2) - 
           32*Power(q1,2)*Power(q2,4)*Power(q3,2) - 
           32*Power(q2,6)*Power(q3,2) + 
           256*Power(q0,3)*q1*q2*Power(q3,3) - 
           896*q0*Power(q1,3)*q2*Power(q3,3) + 
           896*q0*q1*Power(q2,3)*Power(q3,3) + 
           32*Power(q0,2)*Power(q1,2)*Power(q3,4) - 
           64*Power(q1,4)*Power(q3,4) - 
           32*Power(q0,2)*Power(q2,2)*Power(q3,4) + 
           320*Power(q1,2)*Power(q2,2)*Power(q3,4) - 
           64*Power(q2,4)*Power(q3,4) + 128*q0*q1*q2*Power(q3,5) + 
           32*Power(q1,2)*Power(q3,6) - 32*Power(q2,2)*Power(q3,6))*tx + 
        (48*Power(q0,6)*q1*q2 - 224*Power(q0,4)*Power(q1,3)*q2 + 
           48*Power(q0,2)*Power(q1,5)*q2 + 
           224*Power(q0,4)*q1*Power(q2,3) + 
           96*Power(q0,2)*Power(q1,3)*Power(q2,3) + 
           48*Power(q0,2)*q1*Power(q2,5) + 48*Power(q0,5)*Power(q1,2)*q3 - 
           224*Power(q0,3)*Power(q1,4)*q3 + 48*q0*Power(q1,6)*q3 - 
           48*Power(q0,5)*Power(q2,2)*q3 + 
           1344*Power(q0,3)*Power(q1,2)*Power(q2,2)*q3 + 
           48*q0*Power(q1,4)*Power(q2,2)*q3 - 
           224*Power(q0,3)*Power(q2,4)*q3 - 
           48*q0*Power(q1,2)*Power(q2,4)*q3 - 48*q0*Power(q2,6)*q3 + 
           48*Power(q0,4)*q1*q2*Power(q3,2) + 
           1344*Power(q0,2)*Power(q1,3)*q2*Power(q3,2) - 
           48*Power(q1,5)*q2*Power(q3,2) - 
           1344*Power(q0,2)*q1*Power(q2,3)*Power(q3,2) - 
           96*Power(q1,3)*Power(q2,3)*Power(q3,2) - 
           48*q1*Power(q2,5)*Power(q3,2) + 
           96*Power(q0,3)*Power(q1,2)*Power(q3,3) + 
           224*q0*Power(q1,4)*Power(q3,3) - 
           96*Power(q0,3)*Power(q2,2)*Power(q3,3) - 
           1344*q0*Power(q1,2)*Power(q2,2)*Power(q3,3) + 
           224*q0*Power(q2,4)*Power(q3,3) - 
           48*Power(q0,2)*q1*q2*Power(q3,4) - 
           224*Power(q1,3)*q2*Power(q3,4) + 
           224*q1*Power(q2,3)*Power(q3,4) + 
           48*q0*Power(q1,2)*Power(q3,5) - 48*q0*Power(q2,2)*Power(q3,5) - 
           48*q1*q2*Power(q3,6))*ty + 
        (160*Power(q0,5)*Power(q1,2)*q2 - 160*Power(q0,3)*Power(q1,4)*q2 - 
           64*Power(q0,5)*Power(q2,3) - 
           96*Power(q0,3)*Power(q1,2)*Power(q2,3) + 
           64*Power(q0,3)*Power(q2,5) + 160*Power(q0,4)*Power(q1,3)*q3 - 
           160*Power(q0,2)*Power(q1,5)*q3 - 
           512*Power(q0,4)*q1*Power(q2,2)*q3 + 
           352*Power(q0,2)*Power(q1,3)*Power(q2,2)*q3 + 
           512*Power(q0,2)*q1*Power(q2,4)*q3 - 
           352*Power(q0,3)*Power(q1,2)*q2*Power(q3,2) + 
           512*q0*Power(q1,4)*q2*Power(q3,2) + 
           96*Power(q0,3)*Power(q2,3)*Power(q3,2) + 
           352*q0*Power(q1,2)*Power(q2,3)*Power(q3,2) - 
           160*q0*Power(q2,5)*Power(q3,2) + 
           96*Power(q0,2)*Power(q1,3)*Power(q3,3) + 
           64*Power(q1,5)*Power(q3,3) - 
           352*Power(q0,2)*q1*Power(q2,2)*Power(q3,3) - 
           96*Power(q1,3)*Power(q2,2)*Power(q3,3) - 
           160*q1*Power(q2,4)*Power(q3,3) - 
           512*q0*Power(q1,2)*q2*Power(q3,4) + 
           160*q0*Power(q2,3)*Power(q3,4) - 64*Power(q1,3)*Power(q3,5) + 
           160*q1*Power(q2,2)*Power(q3,5))*tz) + 
     tx*((-20*Power(q0,4) + 24*Power(q0,2)*Power(q1,2) - 20*Power(q1,4) - 
           24*Power(q0,2)*Power(q2,2) - 40*Power(q1,2)*Power(q2,2) - 
           20*Power(q2,4) - 96*q0*q1*q2*q3 - 40*Power(q0,2)*Power(q3,2) - 
           24*Power(q1,2)*Power(q3,2) + 24*Power(q2,2)*Power(q3,2) - 
           20*Power(q3,4))*Power(ty,2) + 
        (-32*Power(q0,3)*q1 + 32*q0*Power(q1,3) + 32*q0*q1*Power(q2,2) + 
           32*Power(q0,2)*q2*q3 - 32*Power(q1,2)*q2*q3 - 32*Power(q2,3)*q3 - 
           32*q0*q1*Power(q3,2) + 32*q2*Power(q3,3))*ty*tz))
