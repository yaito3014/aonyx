#include <aonyx.hpp>

using namespace aonyx::dom;
using namespace aonyx::css::style_elements;

// 属性関数の名前空間衝突を避けるために必要なものだけ using します
using aonyx::dom::attrs::charset;
using aonyx::dom::attrs::class_;
using aonyx::dom::attrs::content;
using aonyx::dom::attrs::href;
using aonyx::dom::attrs::lang;
using aonyx::dom::attrs::name;

void top_page(AONYX_PARAM(req, res))
{
    // グローバルなCSS（リセットやホバー、キーフレームなど動的な要素）
    std::string global_css = R"(
        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }
        .btn:hover {
            transform: translateY(-3px);
            box-shadow: 0 8px 25px rgba(0, 114, 255, 0.6);
        }
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(30px); }
            to { opacity: 1; transform: translateY(0); }
        }
    )";

    // CSS-in-C++ で各要素のスタイルを定義
    auto body_style = aonyx::css::rule(
        font_family("'Inter', -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Helvetica, Arial, sans-serif"),
        background("linear-gradient(135deg, #1e1e2f 0%, #151522 100%)"),
        color("#ffffff"),
        display::flex,
        justify_content::center,
        align_items::center,
        height("100vh"),
        aonyx::css::style_element{"overflow", "hidden"} // 未定義のものは直接生成可能
    );

    auto container_style = aonyx::css::rule(
        text_align::center,
        background("rgba(255, 255, 255, 0.05)"),
        aonyx::css::style_element{"backdrop-filter", "blur(12px)"},
        aonyx::css::style_element{"-webkit-backdrop-filter", "blur(12px)"},
        padding("4rem 5rem"),
        border_radius("24px"),
        box_shadow("0 8px 32px rgba(0, 0, 0, 0.3)"),
        border("1px solid rgba(255, 255, 255, 0.1)"),
        aonyx::css::style_element{"animation", "fadeIn 1s ease-out"},
        max_width("600px"),
        width("90%"));

    auto h1_style = aonyx::css::rule(
        font_size("3.5rem"),
        margin_bottom("1.5rem"),
        aonyx::css::style_element{"background-image", "linear-gradient(to right, #00c6ff, #0072ff)"}, // backgroundの代わりにbackground-imageを使用
        aonyx::css::style_element{"-webkit-background-clip", "text"},
        aonyx::css::style_element{"-webkit-text-fill-color", "transparent"},
        font_weight("800"));

    auto p_style = aonyx::css::rule(
        font_size("1.25rem"),
        color("#b0b0c0"),
        margin_bottom("2.5rem"),
        line_height("1.6"));

    auto btn_style = aonyx::css::rule(
        display::inline_block,
        background("linear-gradient(45deg, #00c6ff, #0072ff)"),
        color("white"),
        padding("1rem 2.5rem"),
        border_radius("50px"),
        aonyx::css::style_element{"text-decoration", "none"},
        font_weight("600"),
        font_size("1.1rem"),
        aonyx::css::style_element{"transition", "all 0.3s ease"},
        box_shadow("0 4px 15px rgba(0, 114, 255, 0.4)"));

    // 以前実装した属性ヘルパーをフル活用したDOM構築
    // aonyx::dom::style (タグ) と aonyx::dom::attrs::style (属性) が被るので、
    // 属性側は aonyx::dom::attrs::style とフルで指定するかエイリアスを使います
    namespace attrs = aonyx::dom::attrs;

    auto node = html(lang("en"))(
        head(
            meta(charset("UTF-8")),
            meta(name("viewport"), content("width=device-width, initial-scale=1.0")),
            title("Aonyx Web Framework"),
            aonyx::dom::style(global_css) // タグとしての style
        ),
        body(attrs::style(body_style))( // 属性としての style
            div_(class_("container"), attrs::style(container_style))(
                h1(attrs::style(h1_style))("Welcome to Aonyx"),
                p(attrs::style(p_style))("The next generation C++ web framework. Fast, declarative, and elegant."),
                a(href("https://github.com/Ogame3334/aonyx"), class_("btn"), attrs::style(btn_style))("View on GitHub")
            )
        )
    );

    res.body = node.to_string();
    res.status = 200;
    res.headers["Content-Type"] = "text/html";
}

int main()
{
    aonyx::http::server server;
    auto &router = server.router();

    // / と /top の両方でアクセスできるように設定
    router.get("/", top_page);
    router.get("/top", top_page);

    server.run();

    return 0;
}
