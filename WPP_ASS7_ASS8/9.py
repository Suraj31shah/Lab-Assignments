import re

def gujarati_tokenizer(text):
    patterns = {
        "url": r"https?://(?:[-\w.]|(?:%[\da-fA-F]{2}))+",
        "email": r"[\w\.-]+@[\w\.-]+\.[a-zA-Z]{2,6}",
        "date": r"\d{1,2}[-/.]\d{1,2}[-/.]\d{2,4}",
        "number": r"\d{1,3}(?:,\d{2,3})*(?:\.\d+)?|\d+/\d+|[\u0AE6-\u0AEF]+",
        "username": r"@[\w_]+",
        "punctuation": r"[.,!?;:\"'()\[\]{}]",
        "gujarati_word": r"[\u0A80-\u0AFF]+"
    }
    
    combined_pattern = "|".join(f"(?P<{key}>{pattern})" for key, pattern in patterns.items())
    
    tokens = []
    for match in re.finditer(combined_pattern, text):
        for key, value in match.groupdict().items():
            if value:
                tokens.append((key, value))
    
    return tokens

text = "મારો ઈમેલ abc@gmail.com છે. મારી વેબસાઇટ https://example.com છે. મારી ઉંમર ૧૮ છે!"
tokens = gujarati_tokenizer(text)
print(tokens)