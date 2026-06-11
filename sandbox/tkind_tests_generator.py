import os
import jinja2

def generate_test_file():
    directory = os.path.dirname(__file__);
    # Inicjalizacja środowiska Jinja2 - szuka plików w tym samym katalogu
    template_loader = jinja2.FileSystemLoader(searchpath=directory)
    env = jinja2.Environment(loader=template_loader)
    
    # Definiujemy listę zdarzeń
    events = [
        {
            'name': 'a',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'b',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'c',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'd',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'e',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'f',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'g',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'h',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'i',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'j',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'k',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'l',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'm',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'n',
            'variants': [
                {'suffix': '', 'setup': None, 'logs': 'NULL'}
            ]
        },
        {
            'name': 'o',
            'variants': [
                {
                    'suffix': 'WithFalseChoice1', 
                    'setup': 'tkind_ctest_obj.sm1.b_test_condition = false;', 
                    'logs': 'NULL'
                },
                {
                    'suffix': 'WithTrueChoice1', 
                    'setup': 'tkind_ctest_obj.sm1.b_test_condition = true;', 
                    'logs': 'NULL'
                }
            ]
        }
    ]
    
    # Dane do szablonu
    data = {
        'group_name': 'TkindSm1State9',
        'state_name': 'State9',
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