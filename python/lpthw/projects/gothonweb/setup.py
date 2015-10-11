try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
        'description': 'A Simple Web Project',
        'author': 'Nick Huang',
        'url': 'URL to get it at.',
        'download_url': 'Where to download it.',
        'author_email': 'xjhznick@gmail.com',
        'version': '0.1',
        'install_requires': ['nose'],
        'packages': ['gothonweb'],
        'scripts': [],
        'name': 'project-gothonweb'
        }

setup(**config)
