try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
        'description': 'My project',
        'author': 'Nick Huang',
        'url': 'URL to get it at.',
        'download_url': 'Where to download it.',
        'author_email': 'xjhznick@gmail.com',
        'version': '0.1',
        'install_requires': ['nose'],
        'packages': ['NAME'],
        'scripts': [],
        'name': 'projectName'
        }

setup(**config)
