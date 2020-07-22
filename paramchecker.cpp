#include <list>

class range_validator {
public:
    static bool in_range_exclusive_limit(float llimit, float ulimit, float value)
    {
        return value > llimit && value < ulimit;
    }

    static bool less_than_limit(float llimit, float val)
    {
        return val < llimit;
    }
};

class vital {
public:
    virtual bool is_vital_ok() = 0;
};

class bpm_vital : public vital {
    float _ulimit = 150;
    float _llimit = 70;
    float _bpm;

public:
    bpm_vital(float val) : _bpm(val) {}

    bool  is_vital_ok()
    {
        return range_validator::in_range_exclusive_limit(_llimit, _ulimit, _bpm);
    }
};

class spo2_vital : public vital
{
    float _llimit = 80;
    float _spo2;

public:
    spo2_vital(float val) : _spo2(val) {}

    bool  is_vital_ok()
    {
        return !range_validator::less_than_limit(_llimit, _spo2);
    }
};

class resp_rate_vital : public vital
{
    float _llimit = 30;
    float _ulimit = 60;
    float _resp_rate;

public:
    resp_rate_vital(float val) : _resp_rate(val){}

    bool  is_vital_ok()
    {
        return range_validator::in_range_exclusive_limit(_llimit, _ulimit, _resp_rate);
    }
};

class check_vitals
{
public:
    bool all_vitals_ok(std::list<vital*> vitals)
    {
        for (auto v : vitals)
        {
            if (!v->is_vital_ok())
            {
                return false;
            }
        }
        return true;
    }
};

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  
    std::list<vital*> vitals;
    vitals.push_back(&bpm_vital(bpm));
    vitals.push_back(&spo2_vital(spo2));
    vitals.push_back(&resp_rate_vital(respRate));

    check_vitals vital_condition;

    return vital_condition.all_vitals_ok(vitals);
}
