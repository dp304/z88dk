// cpp/options.yy.cpp generated by reflex 2.0.1 from cpp/options.l

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define REFLEX_OPTION_dotall              true
#define REFLEX_OPTION_fast                true
#define REFLEX_OPTION_freespace           true
#define REFLEX_OPTION_header_file         "cpp/options.yy.h"
#define REFLEX_OPTION_lex                 lex
#define REFLEX_OPTION_lexer               OptionsLexer
#define REFLEX_OPTION_noline              true
#define REFLEX_OPTION_outfile             "cpp/options.yy.cpp"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top user code                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


// silence warnings from RE-flex
#ifdef _MSC_VER
#pragma warning(disable:4102)
#pragma warning(disable:4800)
#else
#ifdef __GNUC__
//#pragma GCC   diagnostic ignored "-Wignored-qualifiers"
#else
#ifdef __clang__
//#pragma clang diagnostic ignored "-Wignored-qualifiers"
#endif
#endif
#endif


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  ABSTRACT LEXER CLASS                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/abslexer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class OptionsLexer : public reflex::AbstractLexer<reflex::Matcher> {
public:
    typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
    OptionsLexer(
        const reflex::Input& input = reflex::Input(),
        std::ostream&        os    = std::cout)
        :
        AbstractBaseLexer(input, os) {
    }
    static const int INITIAL = 0;
    virtual int lex();
    int lex(
        const reflex::Input& input,
        std::ostream*        os = NULL) {
        in(input);
        if (os)
            out(*os);
        return lex();
    }
};

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %{ user code %}                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// z80asm restart
// Copyright (C) Paulo Custodio, 2011-2020
// License: The Artistic License 2.0, http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------


#include "legacy.h"
#include "App.h"

#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>

static int ParseNum(const std::string& text);
static void OptionDefine(const std::string& text);
static const char* SkipEqual(const char* text);


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

extern void reflex_code_INITIAL(reflex::Matcher&);

int OptionsLexer::lex() {
    static const reflex::Pattern PATTERN_INITIAL(reflex_code_INITIAL);
    if (!has_matcher())
        matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
    while (true) {
        switch (matcher().scan()) {
        case 0:
            if (matcher().at_end())
                return int();
            else
                out().put(matcher().input());
            break;
        case 1: // rule at line 52: -\?\z|-h\z :
        { App::ExitManual(); }
        break;
        case 2: // rule at line 53: -v\z :
        { app.options.verbose = true; return true; }
        break;
        case 3: // rule at line 54: -m\z :
        { app.options.mapfile = true; return true; }
        break;
        case 4: // rule at line 55: -s\z :
        { app.options.symtable = true; return true; }
        break;
        case 5: // rule at line 56: -l\z :
        { app.options.listfile = true; return true; }
        break;
        case 6: // rule at line 57: -g\z :
        { app.options.globaldef = true; return true; }
        break;
        case 7: // rule at line 58: -b\z :
        { app.options.makeBinary = true; return true; }
        break;
        case 8: // rule at line 59: -d\z :
        { app.options.update = true; return true; }
        break;
        case 9: // rule at line 60: -R\z :
        { app.options.relocatable = true; return true; }
        break;
        case 10: // rule at line 61: -reloc-info\z :
        { app.options.relocInfo = true; return true; }
        break;
        case 11: // rule at line 62: -split-bin\z :
        { app.options.splitBinary = true; return true; }

        break;
        case 12: // rule at line 64: -m=?z80\z :
        { app.options.cpu.Init(Cpu::Type::Z80); return true; }
        break;
        case 13: // rule at line 65: -m=?z80n\z :
        { app.options.cpu.Init(Cpu::Type::Z80N); return true; }
        break;
        case 14: // rule at line 66: -m=?z180\z :
        { app.options.cpu.Init(Cpu::Type::Z180); return true; }
        break;
        case 15: // rule at line 67: -m=?r2k\z :
        { app.options.cpu.Init(Cpu::Type::R2K); return true; }
        break;
        case 16: // rule at line 68: -m=?r3k\z :
        { app.options.cpu.Init(Cpu::Type::R3K); return true; }
        break;
        case 17: // rule at line 69: -m=?8080\z :
        { app.options.cpu.Init(Cpu::Type::I8080); return true; }
        break;
        case 18: // rule at line 70: -m=?8085\z :
        { app.options.cpu.Init(Cpu::Type::I8085); return true; }
        break;
        case 19: // rule at line 71: -m=?gbz80\z :
        { app.options.cpu.Init(Cpu::Type::GBZ80); return true; }
        break;
        case 20: { // rule at line 72: -m=?ti83\z :
            app.options.cpu.Init(Cpu::Type::Z80);
            app.options.arch.Init(Arch::Type::TI83);
            return true;
        }
        break;
        case 21: { // rule at line 75: -m=?ti83plus\z :
            app.options.cpu.Init(Cpu::Type::Z80);
            app.options.arch.Init(Arch::Type::TI83PLUS);
            return true;
        }
        break;
        case 22: // rule at line 79: -IXIY\z :
        { app.options.swapIxIy = true; return true; }
        break;
        case 23: // rule at line 80: -opt-speed\z :
        { app.options.optimizeSpeed = true; return true; }
        break;
        case 24: // rule at line 81: -debug\z :
        { app.options.SetDebug(); return true; }
        break;
        case 25: // rule at line 82: -I=?[\x00-\xff]+\z :
        { app.options.includePath.push_back(SkipEqual(text() + 2));  return true; }

        break;
        case 26: // rule at line 84: -L=?[\x00-\xff]+\z :
        { app.options.libraryPath.push_back(SkipEqual(text() + 2));  return true; }
        break;
        case 27: // rule at line 85: -x=?[\x00-\xff]+\z :
        { app.options.outputLibrary = SkipEqual(text() + 2); return true; }
        break;
        case 28: // rule at line 86: -l=?[\x00-\xff]+\z :
        { app.options.libraries.push_back(SkipEqual(text() + 2)); return true; }

        break;
        case 29: // rule at line 88: -O=?[\x00-\xff]+\z :
        { app.options.outputDirectory = SkipEqual(text() + 2); return true; }
        break;
        case 30: // rule at line 89: -o=?[\x00-\xff]+\z :
        { app.options.outputFile = SkipEqual(text() + 2); return true; }

        break;
        case 31: { // rule at line 91: -D=?(?:[A-Z_a-z][0-9A-Z_a-z]*)(?:=(?:(?:0[Xx][0-9A-Fa-f]+|\$[0-9A-Fa-f]+|[0-9][0-9A-Fa-f]*[Hh])|(?:[0-9]+)))?\z :
            OptionDefine(SkipEqual(text() + 2)); return true;
        }

        break;
        case 32: // rule at line 94: -r=?(?:(?:0[Xx][0-9A-Fa-f]+|\$[0-9A-Fa-f]+|[0-9][0-9A-Fa-f]*[Hh])|(?:[0-9]+))\z :
        { set_origin_option(ParseNum(SkipEqual(text() + 2))); return true; }

        break;
        case 33: // rule at line 96: \+zx\z :
        { app.options.SetAppmake(Appmake::ZX); return true; }
        break;
        case 34: // rule at line 97: \+zx81\z :
        { app.options.SetAppmake(Appmake::ZX81); return true; }

        break;
        case 35: // rule at line 99: [\x00-\xff] :
        { return false; }

        break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 3: user code                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


// parse NUM
static int ParseNum(const std::string& text) {
    char* end = nullptr;
    const char* p = text.c_str();
    long lval;
    int radix;
    char suffix = '\0';

    if (p[0] == '\0') 		// empty
        return -1;
    else if (p[0] == '$') {
        p++;
        radix = 16;
    }
    else if (p[0] == '0' && tolower(p[1]) == 'x') {
        p += 2;
        radix = 16;
    }
    else if (isdigit(p[0]) && tolower(p[strlen(p) - 1]) == 'h') {
        suffix = p[strlen(p) - 1];
        radix = 16;
    }
    else
        radix = 10;

    lval = strtol(p, &end, radix);
    if (end == nullptr || *end != suffix || errno == ERANGE || lval < 0 || lval > INT_MAX)
        return -1;
    else
        return static_cast<int>(lval);
}

static void OptionDefine(const std::string& text) {
    using namespace std;

    auto p = text.find('=');
    if (p == string::npos) {		// -Dvar
        app.options.defines.push_back({ text, 1});
    }
    else {							// -Dvar=value
        string name = text.substr(0, p);
        int num = ParseNum(text.c_str() + p + 1);
        assert(num >= 0);

        app.options.defines.push_back({ name, num});
    }
}

static const char* SkipEqual(const char* text) {
    if (*text == '=')
        text++;
    return text;
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  TABLES                                                                    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

#if defined(OS_WIN)
#pragma warning(disable:4101 4102)
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-label"
#elif defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-label"
#endif

void reflex_code_INITIAL(reflex::Matcher& m) {
    int c0 = 0, c1 = 0;
    m.FSM_INIT(c1);

S0:
    m.FSM_FIND();
    c1 = m.FSM_CHAR();
    if (c1 == '-') goto S3;
    if (c1 == '+') goto S22;
    if (0 <= c1) goto S25;
    return m.FSM_HALT(c1);

S3:
    m.FSM_TAKE(35);
    c1 = m.FSM_CHAR();
    if (c1 == 'x') goto S66;
    if (c1 == 'v') goto S31;
    if (c1 == 's') goto S41;
    if (c1 == 'r') goto S55;
    if (c1 == 'o') goto S63;
    if (c1 == 'm') goto S33;
    if (c1 == 'l') goto S44;
    if (c1 == 'h') goto S29;
    if (c1 == 'g') goto S46;
    if (c1 == 'd') goto S50;
    if (c1 == 'b') goto S48;
    if (c1 == 'R') goto S53;
    if (c1 == 'O') goto S67;
    if (c1 == 'L') goto S65;
    if (c1 == 'I') goto S61;
    if (c1 == 'D') goto S68;
    if (c1 == '?') goto S27;
    return m.FSM_HALT(c1);

S22:
    m.FSM_TAKE(35);
    c1 = m.FSM_CHAR();
    if (c1 == 'z') goto S73;
    return m.FSM_HALT(c1);

S25:
    m.FSM_TAKE(35);
    return m.FSM_HALT();

S27:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(1, c1);
    return m.FSM_HALT(c1);

S29:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(1, c1);
    return m.FSM_HALT(c1);

S31:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(2, c1);
    return m.FSM_HALT(c1);

S33:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(3, c1);
    if (c1 == 'z') goto S81;
    if (c1 == 't') goto S91;
    if (c1 == 'r') goto S84;
    if (c1 == 'g') goto S89;
    if (c1 == '=') goto S93;
    if (c1 == '8') goto S87;
    return m.FSM_HALT(c1);

S41:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(4, c1);
    if (c1 == 'p') goto S101;
    return m.FSM_HALT(c1);

S44:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(5, c1);
    if (0 <= c1) goto S105;
    return m.FSM_HALT(c1);

S46:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(6, c1);
    return m.FSM_HALT(c1);

S48:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(7, c1);
    return m.FSM_HALT(c1);

S50:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(8, c1);
    if (c1 == 'e') goto S113;
    return m.FSM_HALT(c1);

S53:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(9, c1);
    return m.FSM_HALT(c1);

S55:
    c1 = m.FSM_CHAR();
    if (c1 == 'e') goto S117;
    if (c1 == '=') goto S139;
    if ('1' <= c1 && c1 <= '9') goto S132;
    if (c1 == '0') goto S119;
    if (c1 == '$') goto S128;
    return m.FSM_HALT(c1);

S61:
    c1 = m.FSM_CHAR();
    if (c1 == 'X') goto S143;
    if (0 <= c1) goto S146;
    return m.FSM_HALT(c1);

S63:
    c1 = m.FSM_CHAR();
    if (c1 == 'p') goto S148;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S65:
    c1 = m.FSM_CHAR();
    if (0 <= c1) goto S153;
    return m.FSM_HALT(c1);

S66:
    c1 = m.FSM_CHAR();
    if (0 <= c1) goto S155;
    return m.FSM_HALT(c1);

S67:
    c1 = m.FSM_CHAR();
    if (0 <= c1) goto S157;
    return m.FSM_HALT(c1);

S68:
    c1 = m.FSM_CHAR();
    if ('a' <= c1 && c1 <= 'z') goto S159;
    if (c1 == '_') goto S159;
    if ('A' <= c1 && c1 <= 'Z') goto S159;
    if (c1 == '=') goto S166;
    return m.FSM_HALT(c1);

S73:
    c1 = m.FSM_CHAR();
    if (c1 == 'x') goto S170;
    return m.FSM_HALT(c1);

S75:
    m.FSM_TAKE(1);
    return m.FSM_HALT();

S77:
    m.FSM_TAKE(2);
    return m.FSM_HALT();

S79:
    m.FSM_TAKE(3);
    return m.FSM_HALT();

S81:
    c1 = m.FSM_CHAR();
    if (c1 == '8') goto S173;
    if (c1 == '1') goto S175;
    return m.FSM_HALT(c1);

S84:
    c1 = m.FSM_CHAR();
    if (c1 == '3') goto S179;
    if (c1 == '2') goto S177;
    return m.FSM_HALT(c1);

S87:
    c1 = m.FSM_CHAR();
    if (c1 == '0') goto S181;
    return m.FSM_HALT(c1);

S89:
    c1 = m.FSM_CHAR();
    if (c1 == 'b') goto S183;
    return m.FSM_HALT(c1);

S91:
    c1 = m.FSM_CHAR();
    if (c1 == 'i') goto S185;
    return m.FSM_HALT(c1);

S93:
    c1 = m.FSM_CHAR();
    if (c1 == 'z') goto S81;
    if (c1 == 't') goto S91;
    if (c1 == 'r') goto S84;
    if (c1 == 'g') goto S89;
    if (c1 == '8') goto S87;
    return m.FSM_HALT(c1);

S99:
    m.FSM_TAKE(4);
    return m.FSM_HALT();

S101:
    c1 = m.FSM_CHAR();
    if (c1 == 'l') goto S187;
    return m.FSM_HALT(c1);

S103:
    m.FSM_TAKE(5);
    return m.FSM_HALT();

S105:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(28, c1);
    if (0 <= c1) goto S105;
    return m.FSM_HALT(c1);

S107:
    m.FSM_TAKE(6);
    return m.FSM_HALT();

S109:
    m.FSM_TAKE(7);
    return m.FSM_HALT();

S111:
    m.FSM_TAKE(8);
    return m.FSM_HALT();

S113:
    c1 = m.FSM_CHAR();
    if (c1 == 'b') goto S191;
    return m.FSM_HALT(c1);

S115:
    m.FSM_TAKE(9);
    return m.FSM_HALT();

S117:
    c1 = m.FSM_CHAR();
    if (c1 == 'l') goto S193;
    return m.FSM_HALT(c1);

S119:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(32, c1);
    if (c1 == 'x') goto S195;
    if (c1 == 'h') goto S207;
    if ('a' <= c1 && c1 <= 'f') goto S201;
    if (c1 == 'X') goto S195;
    if (c1 == 'H') goto S207;
    if ('A' <= c1 && c1 <= 'F') goto S201;
    if ('0' <= c1 && c1 <= '9') goto S132;
    return m.FSM_HALT(c1);

S128:
    c1 = m.FSM_CHAR();
    if ('a' <= c1 && c1 <= 'f') goto S210;
    if ('A' <= c1 && c1 <= 'F') goto S210;
    if ('0' <= c1 && c1 <= '9') goto S210;
    return m.FSM_HALT(c1);

S132:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(32, c1);
    if (c1 == 'h') goto S207;
    if ('a' <= c1 && c1 <= 'f') goto S201;
    if (c1 == 'H') goto S207;
    if ('A' <= c1 && c1 <= 'F') goto S201;
    if ('0' <= c1 && c1 <= '9') goto S132;
    return m.FSM_HALT(c1);

S139:
    c1 = m.FSM_CHAR();
    if ('1' <= c1 && c1 <= '9') goto S132;
    if (c1 == '0') goto S119;
    if (c1 == '$') goto S128;
    return m.FSM_HALT(c1);

S143:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(25, c1);
    if (c1 == 'I') goto S215;
    if (0 <= c1) goto S146;
    return m.FSM_HALT(c1);

S146:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(25, c1);
    if (0 <= c1) goto S146;
    return m.FSM_HALT(c1);

S148:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (c1 == 't') goto S220;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S151:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S153:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(26, c1);
    if (0 <= c1) goto S153;
    return m.FSM_HALT(c1);

S155:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(27, c1);
    if (0 <= c1) goto S155;
    return m.FSM_HALT(c1);

S157:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(29, c1);
    if (0 <= c1) goto S157;
    return m.FSM_HALT(c1);

S159:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(31, c1);
    if ('a' <= c1 && c1 <= 'z') goto S159;
    if (c1 == '_') goto S159;
    if ('A' <= c1 && c1 <= 'Z') goto S159;
    if (c1 == '=') goto S233;
    if ('0' <= c1 && c1 <= '9') goto S159;
    return m.FSM_HALT(c1);

S166:
    c1 = m.FSM_CHAR();
    if ('a' <= c1 && c1 <= 'z') goto S159;
    if (c1 == '_') goto S159;
    if ('A' <= c1 && c1 <= 'Z') goto S159;
    return m.FSM_HALT(c1);

S170:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(33, c1);
    if (c1 == '8') goto S239;
    return m.FSM_HALT(c1);

S173:
    c1 = m.FSM_CHAR();
    if (c1 == '0') goto S241;
    return m.FSM_HALT(c1);

S175:
    c1 = m.FSM_CHAR();
    if (c1 == '8') goto S244;
    return m.FSM_HALT(c1);

S177:
    c1 = m.FSM_CHAR();
    if (c1 == 'k') goto S246;
    return m.FSM_HALT(c1);

S179:
    c1 = m.FSM_CHAR();
    if (c1 == 'k') goto S248;
    return m.FSM_HALT(c1);

S181:
    c1 = m.FSM_CHAR();
    if (c1 == '8') goto S250;
    return m.FSM_HALT(c1);

S183:
    c1 = m.FSM_CHAR();
    if (c1 == 'z') goto S253;
    return m.FSM_HALT(c1);

S185:
    c1 = m.FSM_CHAR();
    if (c1 == '8') goto S255;
    return m.FSM_HALT(c1);

S187:
    c1 = m.FSM_CHAR();
    if (c1 == 'i') goto S257;
    return m.FSM_HALT(c1);

S189:
    m.FSM_TAKE(28);
    return m.FSM_HALT();

S191:
    c1 = m.FSM_CHAR();
    if (c1 == 'u') goto S259;
    return m.FSM_HALT(c1);

S193:
    c1 = m.FSM_CHAR();
    if (c1 == 'o') goto S261;
    return m.FSM_HALT(c1);

S195:
    c1 = m.FSM_CHAR();
    if ('a' <= c1 && c1 <= 'f') goto S263;
    if ('A' <= c1 && c1 <= 'F') goto S263;
    if ('0' <= c1 && c1 <= '9') goto S263;
    return m.FSM_HALT(c1);

S199:
    m.FSM_TAKE(32);
    return m.FSM_HALT();

S201:
    c1 = m.FSM_CHAR();
    if (c1 == 'h') goto S268;
    if ('a' <= c1 && c1 <= 'f') goto S201;
    if (c1 == 'H') goto S268;
    if ('A' <= c1 && c1 <= 'F') goto S201;
    if ('0' <= c1 && c1 <= '9') goto S201;
    return m.FSM_HALT(c1);

S207:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(32, c1);
    if ('0' <= c1 && c1 <= '9') goto S207;
    return m.FSM_HALT(c1);

S210:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(32, c1);
    if ('a' <= c1 && c1 <= 'f') goto S210;
    if ('A' <= c1 && c1 <= 'F') goto S210;
    if ('0' <= c1 && c1 <= '9') goto S210;
    return m.FSM_HALT(c1);

S215:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(25, c1);
    if (c1 == 'Y') goto S270;
    if (0 <= c1) goto S146;
    return m.FSM_HALT(c1);

S218:
    m.FSM_TAKE(25);
    return m.FSM_HALT();

S220:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (c1 == '-') goto S272;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S223:
    m.FSM_TAKE(30);
    return m.FSM_HALT();

S225:
    m.FSM_TAKE(26);
    return m.FSM_HALT();

S227:
    m.FSM_TAKE(27);
    return m.FSM_HALT();

S229:
    m.FSM_TAKE(29);
    return m.FSM_HALT();

S231:
    m.FSM_TAKE(31);
    return m.FSM_HALT();

S233:
    c1 = m.FSM_CHAR();
    if ('1' <= c1 && c1 <= '9') goto S288;
    if (c1 == '0') goto S275;
    if (c1 == '$') goto S284;
    return m.FSM_HALT(c1);

S237:
    m.FSM_TAKE(33);
    return m.FSM_HALT();

S239:
    c1 = m.FSM_CHAR();
    if (c1 == '1') goto S295;
    return m.FSM_HALT(c1);

S241:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(12, c1);
    if (c1 == 'n') goto S299;
    return m.FSM_HALT(c1);

S244:
    c1 = m.FSM_CHAR();
    if (c1 == '0') goto S301;
    return m.FSM_HALT(c1);

S246:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(15, c1);
    return m.FSM_HALT(c1);

S248:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(16, c1);
    return m.FSM_HALT(c1);

S250:
    c1 = m.FSM_CHAR();
    if (c1 == '5') goto S309;
    if (c1 == '0') goto S307;
    return m.FSM_HALT(c1);

S253:
    c1 = m.FSM_CHAR();
    if (c1 == '8') goto S311;
    return m.FSM_HALT(c1);

S255:
    c1 = m.FSM_CHAR();
    if (c1 == '3') goto S313;
    return m.FSM_HALT(c1);

S257:
    c1 = m.FSM_CHAR();
    if (c1 == 't') goto S316;
    return m.FSM_HALT(c1);

S259:
    c1 = m.FSM_CHAR();
    if (c1 == 'g') goto S318;
    return m.FSM_HALT(c1);

S261:
    c1 = m.FSM_CHAR();
    if (c1 == 'c') goto S320;
    return m.FSM_HALT(c1);

S263:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(32, c1);
    if ('a' <= c1 && c1 <= 'f') goto S263;
    if ('A' <= c1 && c1 <= 'F') goto S263;
    if ('0' <= c1 && c1 <= '9') goto S263;
    return m.FSM_HALT(c1);

S268:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(32, c1);
    return m.FSM_HALT(c1);

S270:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(22, c1);
    if (0 <= c1) goto S146;
    return m.FSM_HALT(c1);

S272:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (c1 == 's') goto S324;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S275:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(31, c1);
    if (c1 == 'x') goto S327;
    if (c1 == 'h') goto S337;
    if ('a' <= c1 && c1 <= 'f') goto S331;
    if (c1 == 'X') goto S327;
    if (c1 == 'H') goto S337;
    if ('A' <= c1 && c1 <= 'F') goto S331;
    if ('0' <= c1 && c1 <= '9') goto S288;
    return m.FSM_HALT(c1);

S284:
    c1 = m.FSM_CHAR();
    if ('a' <= c1 && c1 <= 'f') goto S340;
    if ('A' <= c1 && c1 <= 'F') goto S340;
    if ('0' <= c1 && c1 <= '9') goto S340;
    return m.FSM_HALT(c1);

S288:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(31, c1);
    if (c1 == 'h') goto S337;
    if ('a' <= c1 && c1 <= 'f') goto S331;
    if (c1 == 'H') goto S337;
    if ('A' <= c1 && c1 <= 'F') goto S331;
    if ('0' <= c1 && c1 <= '9') goto S288;
    return m.FSM_HALT(c1);

S295:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(34, c1);
    return m.FSM_HALT(c1);

S297:
    m.FSM_TAKE(12);
    return m.FSM_HALT();

S299:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(13, c1);
    return m.FSM_HALT(c1);

S301:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(14, c1);
    return m.FSM_HALT(c1);

S303:
    m.FSM_TAKE(15);
    return m.FSM_HALT();

S305:
    m.FSM_TAKE(16);
    return m.FSM_HALT();

S307:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(17, c1);
    return m.FSM_HALT(c1);

S309:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(18, c1);
    return m.FSM_HALT(c1);

S311:
    c1 = m.FSM_CHAR();
    if (c1 == '0') goto S355;
    return m.FSM_HALT(c1);

S313:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(20, c1);
    if (c1 == 'p') goto S359;
    return m.FSM_HALT(c1);

S316:
    c1 = m.FSM_CHAR();
    if (c1 == '-') goto S361;
    return m.FSM_HALT(c1);

S318:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(24, c1);
    return m.FSM_HALT(c1);

S320:
    c1 = m.FSM_CHAR();
    if (c1 == '-') goto S365;
    return m.FSM_HALT(c1);

S322:
    m.FSM_TAKE(22);
    return m.FSM_HALT();

S324:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (c1 == 'p') goto S367;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S327:
    c1 = m.FSM_CHAR();
    if ('a' <= c1 && c1 <= 'f') goto S370;
    if ('A' <= c1 && c1 <= 'F') goto S370;
    if ('0' <= c1 && c1 <= '9') goto S370;
    return m.FSM_HALT(c1);

S331:
    c1 = m.FSM_CHAR();
    if (c1 == 'h') goto S375;
    if ('a' <= c1 && c1 <= 'f') goto S331;
    if (c1 == 'H') goto S375;
    if ('A' <= c1 && c1 <= 'F') goto S331;
    if ('0' <= c1 && c1 <= '9') goto S331;
    return m.FSM_HALT(c1);

S337:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(31, c1);
    if ('0' <= c1 && c1 <= '9') goto S337;
    return m.FSM_HALT(c1);

S340:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(31, c1);
    if ('a' <= c1 && c1 <= 'f') goto S340;
    if ('A' <= c1 && c1 <= 'F') goto S340;
    if ('0' <= c1 && c1 <= '9') goto S340;
    return m.FSM_HALT(c1);

S345:
    m.FSM_TAKE(34);
    return m.FSM_HALT();

S347:
    m.FSM_TAKE(13);
    return m.FSM_HALT();

S349:
    m.FSM_TAKE(14);
    return m.FSM_HALT();

S351:
    m.FSM_TAKE(17);
    return m.FSM_HALT();

S353:
    m.FSM_TAKE(18);
    return m.FSM_HALT();

S355:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(19, c1);
    return m.FSM_HALT(c1);

S357:
    m.FSM_TAKE(20);
    return m.FSM_HALT();

S359:
    c1 = m.FSM_CHAR();
    if (c1 == 'l') goto S379;
    return m.FSM_HALT(c1);

S361:
    c1 = m.FSM_CHAR();
    if (c1 == 'b') goto S381;
    return m.FSM_HALT(c1);

S363:
    m.FSM_TAKE(24);
    return m.FSM_HALT();

S365:
    c1 = m.FSM_CHAR();
    if (c1 == 'i') goto S383;
    return m.FSM_HALT(c1);

S367:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (c1 == 'e') goto S385;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S370:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(31, c1);
    if ('a' <= c1 && c1 <= 'f') goto S370;
    if ('A' <= c1 && c1 <= 'F') goto S370;
    if ('0' <= c1 && c1 <= '9') goto S370;
    return m.FSM_HALT(c1);

S375:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(31, c1);
    return m.FSM_HALT(c1);

S377:
    m.FSM_TAKE(19);
    return m.FSM_HALT();

S379:
    c1 = m.FSM_CHAR();
    if (c1 == 'u') goto S388;
    return m.FSM_HALT(c1);

S381:
    c1 = m.FSM_CHAR();
    if (c1 == 'i') goto S390;
    return m.FSM_HALT(c1);

S383:
    c1 = m.FSM_CHAR();
    if (c1 == 'n') goto S392;
    return m.FSM_HALT(c1);

S385:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (c1 == 'e') goto S394;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S388:
    c1 = m.FSM_CHAR();
    if (c1 == 's') goto S397;
    return m.FSM_HALT(c1);

S390:
    c1 = m.FSM_CHAR();
    if (c1 == 'n') goto S399;
    return m.FSM_HALT(c1);

S392:
    c1 = m.FSM_CHAR();
    if (c1 == 'f') goto S401;
    return m.FSM_HALT(c1);

S394:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(30, c1);
    if (c1 == 'd') goto S403;
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S397:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(21, c1);
    return m.FSM_HALT(c1);

S399:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(11, c1);
    return m.FSM_HALT(c1);

S401:
    c1 = m.FSM_CHAR();
    if (c1 == 'o') goto S409;
    return m.FSM_HALT(c1);

S403:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(23, c1);
    if (0 <= c1) goto S151;
    return m.FSM_HALT(c1);

S405:
    m.FSM_TAKE(21);
    return m.FSM_HALT();

S407:
    m.FSM_TAKE(11);
    return m.FSM_HALT();

S409:
    c1 = m.FSM_CHAR();
    if (m.FSM_META_EOB(c1))
        m.FSM_TAKE(10, c1);
    return m.FSM_HALT(c1);

S411:
    m.FSM_TAKE(23);
    return m.FSM_HALT();

S413:
    m.FSM_TAKE(10);
    return m.FSM_HALT();
}

