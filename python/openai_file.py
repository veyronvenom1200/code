# import openai_secret_manager

# assert "openai" in openai_secret_manager.get_services()
# secrets = openai_secret_manager.get_secrets("openai")

# print(secrets)


import os
import openai
import csv
openai.organization = "org-fM7CEmWB8ZR9OP29eIy7PmXL"
openai.api_key = "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"
openai.Model.list()
stored_responses = dict()
file_path = "output.csv"

# list engines
engines = openai.Engine.list()

# print the first engine's id
print(engines.data[0].id)

user_input = input("Please enter your response: ")


response = openai.Completion.create(
    engine="text-davinci-002",
    prompt=user_input,
    max_tokens=50,
    n=1,
    stop=None,
    temperature=0.7,
)

output = response.choices[0].text.strip()
print(output)

# with open(file_path, "w", newline='') as output_file:
#     csv_writer = csv.writer(output_file)
#     csv_writer.writerow([output])
    # for row in data:
    #     csv_writer.writerow(row)
