import os
import jinja2

def generate_test_file():
    directory = os.path.dirname(__file__);
    # Inicjalizacja środowiska Jinja2 - szuka plików w tym samym katalogu
    template_loader = jinja2.FileSystemLoader(searchpath=directory)
    env = jinja2.Environment(loader=template_loader)
    
    # Definiujemy listę zdarzeń
    events = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o']
    
    # Dane do szablonu
    data = {
        'group_name': 'TkindSm1State4',
        'state_name': 'State4',
        'events': events
    }
    
    # Wczytanie szablonu i renderowanie
    template = env.get_template('tkind_test_template.c.jinja2')
    output = template.render(data)
    
    # Zapis do pliku
    file_path = os.path.join(directory,'TkindSm1StateX_autogen.c')
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(output)
        
    print(f"Pomyślnie wygenerowano plik: {file_path}")

if __name__ == "__main__":
    generate_test_file()