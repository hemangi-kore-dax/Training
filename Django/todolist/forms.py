from django import forms
from todolist.models import Todo
from django.forms import ModelForm

class TodoForm(ModelForm):
    class Meta:
        model=Todo
        fields=['task_title','task_description','to_be_date']