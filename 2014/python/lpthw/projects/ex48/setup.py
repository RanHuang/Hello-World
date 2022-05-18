try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
        'description': 'a simple lexicon',
        'author': 'Nick Huang',
        'url': 'URL to get it at.',
        'download_url': 'Where to download it.',
        'author_email': 'xjhznick@gmail.com',
        'version': '0.1',
        'install_requires': ['nose'],
        'packages': ['ex48'],
        'scripts': [],
        'name': 'projectLexicon'
        }

setup(**config)
