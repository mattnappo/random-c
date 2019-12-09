namespace mal.net;

enum req_type_ : byte { ACCESS, EXEC }

struct loc_ {
    x:double;
    y:double;
    z:double;
    t:double;
}

struct payload_ {
    frame:uint;
    max:uint;
    
    req:req_type_;
    locs[loc_];
}