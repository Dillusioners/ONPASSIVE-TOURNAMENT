from google.cloud import translate

# Set up your Google Cloud project and enable the Translation API.
# Make sure you have the credentials JSON file downloaded and accessible.

def translate_text(text, target_languages):
    # Instantiate the translation client
    translate_client = translate.TranslationServiceClient.from_service_account_json('path/to/credentials.json')

    # Prepare the translation request
    parent = "projects/[YOUR_PROJECT_ID]/locations/global"
    response = translate_client.translate_text(
        request={
            "parent": parent,
            "contents": [text],
            "mime_type": "text/plain",
            "source_language_code": "auto",
            "target_language_codes": target_languages,
        }
    )

    # Extract and return the translated texts
    translated_texts = [translation.translated_text for translation in response.translations]
    return translated_texts

# Example usage
text_to_translate = input("Enter the text : ")
target_languages = ["es", "fr", "de"]  # Spanish, French, German
translated_texts = translate_text(text_to_translate, target_languages)
for language, translation in zip(target_languages, translated_texts):
    print(f"{language}: {translation}")
