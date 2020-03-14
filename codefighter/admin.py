from django.contrib import admin
from .models import *

admin.site.register(CustomUser)
admin.site.register(Problem)
admin.site.register(TestCase)
admin.site.register(Contest)
admin.site.register(Ranklist)
admin.site.register(Submission)
