from collections import namedtuple
from PyQt5.QtGui import QColor

pos_tags = {
    "CC": "Coordinating conjunction",
    "CD": "Cardinal number",
    "DT": "Determiner",
    "EX": "Existential there",
    "FW": "Foreign word",
    "IN": "Preposition or subordinating conjunction",
    "JJ": "Adjective",
    "JJR": "Adjective, comparative",
    "JJS": "Adjective, superlative",
    "LS": "List item marker",
    "MD": "Modal verb",
    "NN": "Noun, singular or mass",
    "NNS": "Noun, plural",
    "NNP": "Proper noun, singular",
    "NNPS": "Proper noun, plural",
    "PDT": "Predeterminer",
    "POS": "Possessive ending",
    "PRP": "Personal pronoun",
    "PRP$": "Possessive pronoun",
    "RB": "Adverb",
    "RBR": "Adverb, comparative",
    "RBS": "Adverb, superlative",
    "RP": "Particle",
    "SYM": "Symbol",
    "TO": "The word 'to'",
    "UH": "Interjection",
    "VB": "Verb, base form",
    "VBD": "Verb, past tense",
    "VBG": "Verb, gerund or present participle",
    "VBN": "Verb, past participle",
    "VBP": "Verb, non-3rd person singular present",
    "VBZ": "Verb, 3rd person singular present",
    "WDT": "Wh-determiner",
    "WP": "Wh-pronoun",
    "WP$": "Possessive wh-pronoun",
    "WRB": "Wh-adverb"
}

# Define the namedtuple for 256-color ANSI color codes
ColorCodes256 = namedtuple("ColorCodes256", [
    "RED", "ORANGE", "YELLOW", "GREEN", "CYAN", "LIGHT_BLUE", "BLUE", "PURPLE",
    "DARK_RED", "DARK_ORANGE", "DARK_YELLOW", "DARK_GREEN", "DARK_CYAN", "DARK_LIGHT_BLUE", "DARK_BLUE", "DARK_PURPLE",
    "BRIGHT_RED", "BRIGHT_ORANGE", "BRIGHT_YELLOW", "BRIGHT_GREEN", "BRIGHT_CYAN", "BRIGHT_LIGHT_BLUE", "BRIGHT_BLUE", "BRIGHT_PURPLE",
    "PASTEL_RED", "PASTEL_ORANGE", "PASTEL_YELLOW", "PASTEL_GREEN", "PASTEL_CYAN", "PASTEL_LIGHT_BLUE", "PASTEL_BLUE", "PASTEL_PURPLE",
    "GRAY1", "GRAY2", "GRAY3", "GRAY4"
])

# Initialize the namedtuple with selected ANSI color codes for 256-color mode
color_codes_256 = ColorCodes256(
    196, 202, 226, 46, 51, 39, 21, 127,
    160, 166, 190, 34, 39, 27, 18, 90,
    203, 209, 229, 47, 51, 39, 21, 128,
    203, 214, 227, 48, 52, 40, 22, 129,
    236, 239, 242, 245
)

def ansi_to_qcolor(ansi_code):
    if 0 <= ansi_code <= 15:
        # 16 basic colors
        table = [
            0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080, 0xc0c0c0,
            0x808080, 0xff0000, 0x00ff00, 0xffff00, 0x0000ff, 0xff00ff, 0x00ffff, 0xffffff
        ]
        return QColor(table[ansi_code])
    elif 16 <= ansi_code <= 231:
        # 216 colors (6x6x6 RGB color cube)
        ansi_code -= 16
        r = ansi_code // 36
        g = (ansi_code % 36) // 6
        b = ansi_code % 6
        return QColor(r * 51, g * 51, b * 51)
    elif 232 <= ansi_code <= 255:
        # 24 grayscale colors
        level = (ansi_code - 232) * 10 + 8
        return QColor(level, level, level)
    else:
        raise ValueError(f"Invalid ANSI color code: {ansi_code}")

color_codes_256 = [
    196, 202, 226, 46, 51, 39, 21, 127,
    160, 166, 190, 34, 39, 27, 18, 90,
    203, 209, 229, 47, 51, 39, 21, 128,
    203, 214, 227, 48, 52, 40, 22, 129,
    236, 239, 242, 245
]

qcolors_temp = [ansi_to_qcolor(ansi_code) for ansi_code in color_codes_256]
qcolors = ColorCodes256(*qcolors_temp)
print(qcolors)
pos_tag_colors = dict(zip(pos_tags.keys(), qcolors))
# print(pos_tag_colors)