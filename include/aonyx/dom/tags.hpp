#pragma once

namespace aonyx
{
    namespace dom
    {
        enum class tags
        {
            // Document metadata
            HTML,
            HEAD,
            TITLE,
            BASE,
            LINK,
            META,
            STYLE,

            // Sections
            BODY,
            ARTICLE,
            SECTION,
            NAV,
            ASIDE,
            H1,
            H2,
            H3,
            H4,
            H5,
            H6,
            HEADER,
            FOOTER,
            ADDRESS,

            // Grouping content
            P,
            HR,
            PRE,
            BLOCKQUOTE,
            OL,
            UL,
            MENU,
            LI,
            DL,
            DT,
            DD,
            FIGURE,
            FIGCAPTION,
            MAIN,
            DIV,

            // Text-level semantics
            A,
            EM,
            STRONG,
            SMALL,
            S,
            CITE,
            Q,
            DFN,
            ABBR,
            DATA,
            TIME,
            CODE,
            VAR,
            SAMP,
            KBD,
            SUB,
            SUP,
            I,
            B,
            U,
            MARK,
            RUBY,
            RT,
            RP,
            BDI,
            BDO,
            SPAN,
            BR,
            WBR,

            // Edits
            INS,
            DEL,

            // Embedded content
            PICTURE,
            SOURCE,
            IMG,
            IFRAME,
            EMBED,
            OBJECT,
            PARAM,
            VIDEO,
            AUDIO,
            TRACK,
            MAP,
            AREA,

            // SVG / MathML roots
            SVG,
            MATH,

            // Scripting
            SCRIPT,
            NOSCRIPT,
            CANVAS,

            // Demarcating edits
            TEMPLATE,
            SLOT,

            // Tables
            TABLE,
            CAPTION,
            COLGROUP,
            COL,
            THEAD,
            TBODY,
            TFOOT,
            TR,
            TD,
            TH,

            // Forms
            FORM,
            LABEL,
            INPUT,
            BUTTON,
            SELECT,
            DATALIST,
            OPTGROUP,
            OPTION,
            TEXTAREA,
            OUTPUT,
            PROGRESS,
            METER,
            FIELDSET,
            LEGEND,

            // Interactive elements
            DETAILS,
            SUMMARY,
            DIALOG,

            // Web Components
            SLOT_ELEMENT,

            NONE,
            UNKNOWN
        };

        constexpr std::string_view tags2str(tags tag) noexcept
        {
            switch (tag)
            {
            case tags::HTML:
                return "html";
            case tags::HEAD:
                return "head";
            case tags::TITLE:
                return "title";
            case tags::BASE:
                return "base";
            case tags::LINK:
                return "link";
            case tags::META:
                return "meta";
            case tags::STYLE:
                return "style";

            case tags::BODY:
                return "body";
            case tags::ARTICLE:
                return "article";
            case tags::SECTION:
                return "section";
            case tags::NAV:
                return "nav";
            case tags::ASIDE:
                return "aside";
            case tags::H1:
                return "h1";
            case tags::H2:
                return "h2";
            case tags::H3:
                return "h3";
            case tags::H4:
                return "h4";
            case tags::H5:
                return "h5";
            case tags::H6:
                return "h6";
            case tags::HEADER:
                return "header";
            case tags::FOOTER:
                return "footer";
            case tags::ADDRESS:
                return "address";

            case tags::P:
                return "p";
            case tags::HR:
                return "hr";
            case tags::PRE:
                return "pre";
            case tags::BLOCKQUOTE:
                return "blockquote";
            case tags::OL:
                return "ol";
            case tags::UL:
                return "ul";
            case tags::MENU:
                return "menu";
            case tags::LI:
                return "li";
            case tags::DL:
                return "dl";
            case tags::DT:
                return "dt";
            case tags::DD:
                return "dd";
            case tags::FIGURE:
                return "figure";
            case tags::FIGCAPTION:
                return "figcaption";
            case tags::MAIN:
                return "main";
            case tags::DIV:
                return "div";

            case tags::A:
                return "a";
            case tags::EM:
                return "em";
            case tags::STRONG:
                return "strong";
            case tags::SMALL:
                return "small";
            case tags::S:
                return "s";
            case tags::CITE:
                return "cite";
            case tags::Q:
                return "q";
            case tags::DFN:
                return "dfn";
            case tags::ABBR:
                return "abbr";
            case tags::DATA:
                return "data";
            case tags::TIME:
                return "time";
            case tags::CODE:
                return "code";
            case tags::VAR:
                return "var";
            case tags::SAMP:
                return "samp";
            case tags::KBD:
                return "kbd";
            case tags::SUB:
                return "sub";
            case tags::SUP:
                return "sup";
            case tags::I:
                return "i";
            case tags::B:
                return "b";
            case tags::U:
                return "u";
            case tags::MARK:
                return "mark";
            case tags::RUBY:
                return "ruby";
            case tags::RT:
                return "rt";
            case tags::RP:
                return "rp";
            case tags::BDI:
                return "bdi";
            case tags::BDO:
                return "bdo";
            case tags::SPAN:
                return "span";
            case tags::BR:
                return "br";
            case tags::WBR:
                return "wbr";

            case tags::INS:
                return "ins";
            case tags::DEL:
                return "del";

            case tags::PICTURE:
                return "picture";
            case tags::SOURCE:
                return "source";
            case tags::IMG:
                return "img";
            case tags::IFRAME:
                return "iframe";
            case tags::EMBED:
                return "embed";
            case tags::OBJECT:
                return "object";
            case tags::PARAM:
                return "param";
            case tags::VIDEO:
                return "video";
            case tags::AUDIO:
                return "audio";
            case tags::TRACK:
                return "track";
            case tags::MAP:
                return "map";
            case tags::AREA:
                return "area";

            case tags::SVG:
                return "svg";
            case tags::MATH:
                return "math";

            case tags::SCRIPT:
                return "script";
            case tags::NOSCRIPT:
                return "noscript";
            case tags::CANVAS:
                return "canvas";

            case tags::TEMPLATE:
                return "template";
            case tags::SLOT:
                return "slot";

            case tags::TABLE:
                return "table";
            case tags::CAPTION:
                return "caption";
            case tags::COLGROUP:
                return "colgroup";
            case tags::COL:
                return "col";
            case tags::THEAD:
                return "thead";
            case tags::TBODY:
                return "tbody";
            case tags::TFOOT:
                return "tfoot";
            case tags::TR:
                return "tr";
            case tags::TD:
                return "td";
            case tags::TH:
                return "th";

            case tags::FORM:
                return "form";
            case tags::LABEL:
                return "label";
            case tags::INPUT:
                return "input";
            case tags::BUTTON:
                return "button";
            case tags::SELECT:
                return "select";
            case tags::DATALIST:
                return "datalist";
            case tags::OPTGROUP:
                return "optgroup";
            case tags::OPTION:
                return "option";
            case tags::TEXTAREA:
                return "textarea";
            case tags::OUTPUT:
                return "output";
            case tags::PROGRESS:
                return "progress";
            case tags::METER:
                return "meter";
            case tags::FIELDSET:
                return "fieldset";
            case tags::LEGEND:
                return "legend";

            case tags::DETAILS:
                return "details";
            case tags::SUMMARY:
                return "summary";
            case tags::DIALOG:
                return "dialog";
            }

            return "";
        }

        constexpr tags
        str2tags(std::string_view tag) noexcept
        {
            if (tag == "html")
                return tags::HTML;
            if (tag == "head")
                return tags::HEAD;
            if (tag == "title")
                return tags::TITLE;
            if (tag == "base")
                return tags::BASE;
            if (tag == "link")
                return tags::LINK;
            if (tag == "meta")
                return tags::META;
            if (tag == "style")
                return tags::STYLE;

            if (tag == "body")
                return tags::BODY;
            if (tag == "article")
                return tags::ARTICLE;
            if (tag == "section")
                return tags::SECTION;
            if (tag == "nav")
                return tags::NAV;
            if (tag == "aside")
                return tags::ASIDE;
            if (tag == "h1")
                return tags::H1;
            if (tag == "h2")
                return tags::H2;
            if (tag == "h3")
                return tags::H3;
            if (tag == "h4")
                return tags::H4;
            if (tag == "h5")
                return tags::H5;
            if (tag == "h6")
                return tags::H6;
            if (tag == "header")
                return tags::HEADER;
            if (tag == "footer")
                return tags::FOOTER;
            if (tag == "address")
                return tags::ADDRESS;

            if (tag == "p")
                return tags::P;
            if (tag == "hr")
                return tags::HR;
            if (tag == "pre")
                return tags::PRE;
            if (tag == "blockquote")
                return tags::BLOCKQUOTE;
            if (tag == "ol")
                return tags::OL;
            if (tag == "ul")
                return tags::UL;
            if (tag == "menu")
                return tags::MENU;
            if (tag == "li")
                return tags::LI;
            if (tag == "dl")
                return tags::DL;
            if (tag == "dt")
                return tags::DT;
            if (tag == "dd")
                return tags::DD;
            if (tag == "figure")
                return tags::FIGURE;
            if (tag == "figcaption")
                return tags::FIGCAPTION;
            if (tag == "main")
                return tags::MAIN;
            if (tag == "div")
                return tags::DIV;

            if (tag == "a")
                return tags::A;
            if (tag == "em")
                return tags::EM;
            if (tag == "strong")
                return tags::STRONG;
            if (tag == "small")
                return tags::SMALL;
            if (tag == "s")
                return tags::S;
            if (tag == "cite")
                return tags::CITE;
            if (tag == "q")
                return tags::Q;
            if (tag == "dfn")
                return tags::DFN;
            if (tag == "abbr")
                return tags::ABBR;
            if (tag == "data")
                return tags::DATA;
            if (tag == "time")
                return tags::TIME;
            if (tag == "code")
                return tags::CODE;
            if (tag == "var")
                return tags::VAR;
            if (tag == "samp")
                return tags::SAMP;
            if (tag == "kbd")
                return tags::KBD;
            if (tag == "sub")
                return tags::SUB;
            if (tag == "sup")
                return tags::SUP;
            if (tag == "i")
                return tags::I;
            if (tag == "b")
                return tags::B;
            if (tag == "u")
                return tags::U;
            if (tag == "mark")
                return tags::MARK;
            if (tag == "ruby")
                return tags::RUBY;
            if (tag == "rt")
                return tags::RT;
            if (tag == "rp")
                return tags::RP;
            if (tag == "bdi")
                return tags::BDI;
            if (tag == "bdo")
                return tags::BDO;
            if (tag == "span")
                return tags::SPAN;
            if (tag == "br")
                return tags::BR;
            if (tag == "wbr")
                return tags::WBR;

            if (tag == "ins")
                return tags::INS;
            if (tag == "del")
                return tags::DEL;

            if (tag == "picture")
                return tags::PICTURE;
            if (tag == "source")
                return tags::SOURCE;
            if (tag == "img")
                return tags::IMG;
            if (tag == "iframe")
                return tags::IFRAME;
            if (tag == "embed")
                return tags::EMBED;
            if (tag == "object")
                return tags::OBJECT;
            if (tag == "param")
                return tags::PARAM;
            if (tag == "video")
                return tags::VIDEO;
            if (tag == "audio")
                return tags::AUDIO;
            if (tag == "track")
                return tags::TRACK;
            if (tag == "map")
                return tags::MAP;
            if (tag == "area")
                return tags::AREA;

            if (tag == "svg")
                return tags::SVG;
            if (tag == "math")
                return tags::MATH;

            if (tag == "script")
                return tags::SCRIPT;
            if (tag == "noscript")
                return tags::NOSCRIPT;
            if (tag == "canvas")
                return tags::CANVAS;

            if (tag == "template")
                return tags::TEMPLATE;
            if (tag == "slot")
                return tags::SLOT;

            if (tag == "table")
                return tags::TABLE;
            if (tag == "caption")
                return tags::CAPTION;
            if (tag == "colgroup")
                return tags::COLGROUP;
            if (tag == "col")
                return tags::COL;
            if (tag == "thead")
                return tags::THEAD;
            if (tag == "tbody")
                return tags::TBODY;
            if (tag == "tfoot")
                return tags::TFOOT;
            if (tag == "tr")
                return tags::TR;
            if (tag == "td")
                return tags::TD;
            if (tag == "th")
                return tags::TH;

            if (tag == "form")
                return tags::FORM;
            if (tag == "label")
                return tags::LABEL;
            if (tag == "input")
                return tags::INPUT;
            if (tag == "button")
                return tags::BUTTON;
            if (tag == "select")
                return tags::SELECT;
            if (tag == "datalist")
                return tags::DATALIST;
            if (tag == "optgroup")
                return tags::OPTGROUP;
            if (tag == "option")
                return tags::OPTION;
            if (tag == "textarea")
                return tags::TEXTAREA;
            if (tag == "output")
                return tags::OUTPUT;
            if (tag == "progress")
                return tags::PROGRESS;
            if (tag == "meter")
                return tags::METER;
            if (tag == "fieldset")
                return tags::FIELDSET;
            if (tag == "legend")
                return tags::LEGEND;

            if (tag == "details")
                return tags::DETAILS;
            if (tag == "summary")
                return tags::SUMMARY;
            if (tag == "dialog")
                return tags::DIALOG;

            if (tag == "")
            {
                return tags::NONE;
            }

            return tags::UNKNOWN;
        }
    }
}
