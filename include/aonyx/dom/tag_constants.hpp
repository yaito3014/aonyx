#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <type_traits>

#include <aonyx/dom/html_tag.hpp>
#include <aonyx/dom/tags.hpp>

namespace aonyx
{
    namespace dom
    {
        // Document metadata
        inline constexpr html_tag html{tags::HTML};
        inline constexpr html_tag head{tags::HEAD};
        inline constexpr html_tag title{tags::TITLE};
        inline constexpr html_tag base{tags::BASE};
        inline constexpr html_tag link{tags::LINK};
        inline constexpr html_tag meta{tags::META};
        inline constexpr html_tag style{tags::STYLE};

        // Sections
        inline constexpr html_tag body{tags::BODY};
        inline constexpr html_tag article{tags::ARTICLE};
        inline constexpr html_tag section{tags::SECTION};
        inline constexpr html_tag nav{tags::NAV};
        inline constexpr html_tag aside{tags::ASIDE};
        inline constexpr html_tag h1{tags::H1};
        inline constexpr html_tag h2{tags::H2};
        inline constexpr html_tag h3{tags::H3};
        inline constexpr html_tag h4{tags::H4};
        inline constexpr html_tag h5{tags::H5};
        inline constexpr html_tag h6{tags::H6};
        inline constexpr html_tag header{tags::HEADER};
        inline constexpr html_tag footer{tags::FOOTER};
        inline constexpr html_tag address{tags::ADDRESS};

        // Grouping content
        inline constexpr html_tag p{tags::P};
        inline constexpr html_tag hr{tags::HR};
        inline constexpr html_tag pre{tags::PRE};
        inline constexpr html_tag blockquote{tags::BLOCKQUOTE};
        inline constexpr html_tag ol{tags::OL};
        inline constexpr html_tag ul{tags::UL};
        inline constexpr html_tag menu{tags::MENU};
        inline constexpr html_tag li{tags::LI};
        inline constexpr html_tag dl{tags::DL};
        inline constexpr html_tag dt{tags::DT};
        inline constexpr html_tag dd{tags::DD};
        inline constexpr html_tag figure{tags::FIGURE};
        inline constexpr html_tag figcaption{tags::FIGCAPTION};
        inline constexpr html_tag main_{tags::MAIN};
        inline constexpr html_tag div_{tags::DIV};

        // Text-level semantics
        inline constexpr html_tag a{tags::A};
        inline constexpr html_tag em{tags::EM};
        inline constexpr html_tag strong{tags::STRONG};
        inline constexpr html_tag small{tags::SMALL};
        inline constexpr html_tag s{tags::S};
        inline constexpr html_tag cite{tags::CITE};
        inline constexpr html_tag q{tags::Q};
        inline constexpr html_tag dfn{tags::DFN};
        inline constexpr html_tag abbr{tags::ABBR};
        inline constexpr html_tag data{tags::DATA};
        inline constexpr html_tag time{tags::TIME};
        inline constexpr html_tag code{tags::CODE};
        inline constexpr html_tag var{tags::VAR};
        inline constexpr html_tag samp{tags::SAMP};
        inline constexpr html_tag kbd{tags::KBD};
        inline constexpr html_tag sub{tags::SUB};
        inline constexpr html_tag sup{tags::SUP};
        inline constexpr html_tag i{tags::I};
        inline constexpr html_tag b{tags::B};
        inline constexpr html_tag u{tags::U};
        inline constexpr html_tag mark{tags::MARK};
        inline constexpr html_tag ruby{tags::RUBY};
        inline constexpr html_tag rt{tags::RT};
        inline constexpr html_tag rp{tags::RP};
        inline constexpr html_tag bdi{tags::BDI};
        inline constexpr html_tag bdo{tags::BDO};
        inline constexpr html_tag span{tags::SPAN};
        inline constexpr html_tag br{tags::BR};
        inline constexpr html_tag wbr{tags::WBR};

        // Edits
        inline constexpr html_tag ins{tags::INS};
        inline constexpr html_tag del{tags::DEL};

        // Embedded content
        inline constexpr html_tag picture{tags::PICTURE};
        inline constexpr html_tag source{tags::SOURCE};
        inline constexpr html_tag img{tags::IMG};
        inline constexpr html_tag iframe{tags::IFRAME};
        inline constexpr html_tag embed{tags::EMBED};
        inline constexpr html_tag object{tags::OBJECT};
        inline constexpr html_tag param{tags::PARAM};
        inline constexpr html_tag video{tags::VIDEO};
        inline constexpr html_tag audio{tags::AUDIO};
        inline constexpr html_tag track{tags::TRACK};
        inline constexpr html_tag map{tags::MAP};
        inline constexpr html_tag area{tags::AREA};

        // SVG / MathML roots
        inline constexpr html_tag svg{tags::SVG};
        inline constexpr html_tag math{tags::MATH};

        // Scripting
        inline constexpr html_tag script{tags::SCRIPT};
        inline constexpr html_tag noscript{tags::NOSCRIPT};
        inline constexpr html_tag canvas{tags::CANVAS};

        // Templates
        inline constexpr html_tag template_{tags::TEMPLATE};
        inline constexpr html_tag slot{tags::SLOT};

        // Tables
        inline constexpr html_tag table{tags::TABLE};
        inline constexpr html_tag caption{tags::CAPTION};
        inline constexpr html_tag colgroup{tags::COLGROUP};
        inline constexpr html_tag col{tags::COL};
        inline constexpr html_tag thead{tags::THEAD};
        inline constexpr html_tag tbody{tags::TBODY};
        inline constexpr html_tag tfoot{tags::TFOOT};
        inline constexpr html_tag tr{tags::TR};
        inline constexpr html_tag td{tags::TD};
        inline constexpr html_tag th{tags::TH};

        // Forms
        inline constexpr html_tag form{tags::FORM};
        inline constexpr html_tag label{tags::LABEL};
        inline constexpr html_tag input{tags::INPUT};
        inline constexpr html_tag button{tags::BUTTON};
        inline constexpr html_tag select{tags::SELECT};
        inline constexpr html_tag datalist{tags::DATALIST};
        inline constexpr html_tag optgroup{tags::OPTGROUP};
        inline constexpr html_tag option{tags::OPTION};
        inline constexpr html_tag textarea{tags::TEXTAREA};
        inline constexpr html_tag output{tags::OUTPUT};
        inline constexpr html_tag progress{tags::PROGRESS};
        inline constexpr html_tag meter{tags::METER};
        inline constexpr html_tag fieldset{tags::FIELDSET};
        inline constexpr html_tag legend{tags::LEGEND};

        // Interactive elements
        inline constexpr html_tag details{tags::DETAILS};
        inline constexpr html_tag summary{tags::SUMMARY};
        inline constexpr html_tag dialog{tags::DIALOG};

        // Web Components
        inline constexpr html_tag slot_element{tags::SLOT_ELEMENT};
    } // namespace dom
} // namespace aonyx
