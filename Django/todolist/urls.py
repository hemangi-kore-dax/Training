from django.urls import path
from . import views

urlpatterns = [
    path('', views.task_list, name="task_list"),
    path('add/', views.add_todo, name="add_todo"),
    path('delete/?P<int:id>/', views.delete, name="delete"),
    path('update/?P<int:id>/', views.update, name="update"),
    path('update_not_completed/?P<int:id>/', views.update_not_completed, name="update_not_completed"),
    path('edit/?P<int:id>/', views.edit, name="edit"),
    # path('update_in_db/?P<int:id>/', views.update_in_db, name="update_in_db"),
]
