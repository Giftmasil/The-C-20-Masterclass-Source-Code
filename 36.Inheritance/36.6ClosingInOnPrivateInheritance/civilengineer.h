#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream&, const CivilEngineer& operand);
    friend struct fmt::formatter<CivilEngineer>;
public:
    CivilEngineer();
    ~CivilEngineer() ;
    
    void build_road(){
        //get_full_name(); // Compiler error
        ///m_full_name = "Daniel Gray"; //Compiler error
        //m_age = 45; // Compiler error
    }
	
private : 
    std::string m_speciality{"None"};

};

/**
* CivilEngineer obj fmt's output overload
- reference: https://fmt.dev/latest/api.html
*/
template<>
struct fmt::formatter<CivilEngineer> {
    constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const CivilEngineer &obj, FormatContext &ctx) {
        /*return format_to(
            ctx.out(), "CivilEngineer [ Full name: {}, Age: {}, Address: {}, Contract Count: {}, specialty: {}]",
            obj.get_full_name(), obj.get_age(), obj.get_address(), obj.contract_count, obj.m_speciality);*/
    }
};
#endif // CIVIL_ENGINEER_H
